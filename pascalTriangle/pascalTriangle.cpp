#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> arr(numRows);
        int i, j, val;

        for(i = 1; i <= numRows; ++i)
        {     
            for(j = 0; j < i; ++j)
            {
                if(j == 0 || j == (i - 1))
                {
                    val = 1;
                    arr[i-1].push_back(val);
                }
                else
                {
                    val = arr[i - 2][j - 1] + arr[i - 2][j];
                    arr[i-1].push_back(val);
                }
            }
        }

        return arr;
    }
};

int main()
{
    int n, i, j;
    Solution s;
    
    cin >> n;
    vector<vector<int>> arr(n);
    arr = s.generate(n);

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < arr[i].size(); ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}