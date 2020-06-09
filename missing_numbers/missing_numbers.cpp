#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

/*int b_search(vector<int> brr, int value, vector<int>::iterator lower, vector<int>::iterator upper)
{
    while(lower <= upper)
    {
        vector<int>::iterator mid = lower + distance(lower, upper)/2;

        if(*mid == value)
        {
            *mid = -1;
            return 1;
        }
        else if(*mid < value)
        {
            lower = mid + 1;
        }
        else
        {
            upper = mid - 1;
        }
    }

    return 0;
}*/

vector<int> missing_numbers(vector<int> arr, vector<int> brr)
{
    vector<int> missing;
    vector<int>::iterator i, k;

    sort(brr.begin(), brr.end());
    sort(arr.begin(), arr.end());

    for(i = brr.begin(); i != brr.end(); ++i)
    {
        //if(!b_search(arr, *i, arr.begin(), arr.end()))
        if(!binary_search(arr.begin(), arr.end(), *i))
        {
            missing.push_back(*i);
        }
        else
        {
            for(k = arr.begin(); k != arr.end(); ++k)
            {
                if(*k == *i)
                {
                    *k = -1;
                    break;
                }
            }
        }
        
    }
    vector<int>::iterator u = unique(missing.begin(), missing.end());
    missing.resize(distance(missing.begin(), u));
    return missing;
}

int main()
{
    int n, m, val;
    vector<int> arr;
    vector<int> brr;
    vector<int> missing;
    
    cin >> n ;
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        arr.push_back(val);
    }
    
    cin >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> val;
        brr.push_back(val);
    }

    missing = missing_numbers(arr, brr);
    
    for(vector<int>::iterator j = missing.begin(); j != missing.end(); ++j)
    {
        cout << *j << " ";
    }
}


