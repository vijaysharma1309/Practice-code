#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

map<char, int> bad_char(string patt)
{
    map<char, int> pa_arr;
    int i, val;
    int size = patt.size();
    for(i = 0; i < size; ++i)
    {
        val = patt.size() - i - 1;
        pa_arr.insert({patt[i], val});
        pa_arr.at(patt[i]) = val;
    }

    val = size;
    pa_arr.at(patt[size-1]) = val;

    return pa_arr;
}

vector<int> search_substring(string text, string patt, map<char, int> pa_arr)
{
    int p_index = patt.size() - 1;
    map<char, int>::iterator it;
    vector<int> search_index;

    for(int j = 0; j < text.size(); ++j)
    {
        while(p_index >= 0 && patt[p_index] == text[j + p_index])
        {
            --p_index;
        }

        if(p_index < 0)
        {
            search_index.push_back(j);
        }
        else
        {
            it = pa_arr.find(text[j + p_index]);
            if(it != pa_arr.end())
            {
                j += it->second - 1;
            }
            else
            {
                j += patt.size() - 1;
            }
        }
        p_index = patt.size() - 1;
    }

    return search_index;
}

bool grid_search(string *grid, string *pat, int grid_row, int pat_row)
{
    int i, p = 0;
    vector<int> search_index;
    int size = pat[0].size();
    map<char, int> pa_arr;
    pa_arr = bad_char(pat[0]);
    
    for(i = 0; i <= grid_row - pat_row; ++i)
    {
        search_index = search_substring(grid[i], pat[0], pa_arr);
        for(auto it = search_index.begin(); it != search_index.end(); ++it)
        {
            p = 0;
            for(int j = i+1; j <= grid_row; ++j)
            {
                if(p < pat_row)
                {
                    if((grid[j].compare(*it, size, pat[++p])))
                    {
                        break;
                    }
                }
                if(p == pat_row - 1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int t, i, grid_row, grid_col, pat_row, pat_col;
    string text, patt;

    cin >> t;

    while(t--)
    {
        cin >> grid_row >> grid_col;
        string grid[grid_row];
        for(i = 0; i < grid_row; ++i)
        {
            cin >> grid[i];
        }
        
        cin >> pat_row >> pat_col;
        string pat[pat_row];
        for(i = 0; i < pat_row; ++i)
        {
            cin >> pat[i];
        }
        
        if(grid_search(grid, pat, grid_row, pat_row))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

