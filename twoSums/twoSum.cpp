#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) 
    {
        int i, j, len = arr.size();
        vector<int> nums;

        for(i = 0; i < len; ++i)
        {
            for(j = i+1; j < len; ++j)
            {
                if((arr[i] + arr[j]) == target)
                {
                    nums.push_back(i);
                    nums.push_back(j);
                    return nums;
                }
            }
        }

        return nums;
    }
};

int main()
{
    int n, val, target;
    vector<int> arr;
    Solution s;
    
    cin >> n ;
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        arr.push_back(val);
    }

    cin >> target;

    arr = s.twoSum(arr, target);

    cout << arr[0] << " " << arr[1];
}