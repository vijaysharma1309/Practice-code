#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

vector<int> missing_numbers(vector<int> arr, vector<int> brr)
{
    vector<int> missing;
    vector<int>::iterator i;
    int arr_count[101] = {0}, brr_count[101] = {0};
    int brr_min, val;

    brr_min = *min_element(brr.begin(), brr.end());

    for(i = arr.begin(); i != arr.end(); ++i)
    {
        ++arr_count[*i - brr_min];
    }
    
    for(i = brr.begin(); i != brr.end(); ++i)
    {
        ++brr_count[*i - brr_min];
    }

    for(int j = 0; j < 101; ++j)
    {
        if(arr_count[j] == brr_count[j])
            continue;
        val = brr_min + j;
        missing.push_back(val);
    }
    
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
