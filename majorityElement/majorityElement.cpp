#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> arr)
    {
        int count = 1, half = arr.size()/2;
        int s = arr.size(), i, res = -1;
        
        sort(arr.begin(), arr.end());

        for(i = 1; i < s; ++i)
        {   
            if(arr[i] == arr[i-1])
                ++count;
            else
            {
                if(count > half)
                    return arr[i-1];
                else
                {
                    count = 1;
                }
            }
        }
        if(count > half)
            res = arr[i-1];
            
        return res;
    }
};

int main()
{
    int n, val;
    vector<int> arr;
    Solution s;
    
    cin >> n ;
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        arr.push_back(val);
    }

    cout << s.majorityElement(arr);
}