#include <bits/stdc++.h> 
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& arr) 
    {
        vector<int> num;
        int i, val = 0, carry = 0;
        int n = arr.size();

        for(i = n - 1; i >= 0; --i)
        {
            if(i == (n - 1))
            {
                carry = 1;
            }
            val = arr[i] + carry;
            num.insert(num.begin(), val%10);
            if(val == 10)
                carry = 1;
            else
                carry = 0;
        }
        if(carry)
        {
            num.insert(num.begin(), carry);
        }

        return num;
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

    arr = s.plusOne(arr);

    for(vector<int>::iterator k = arr.begin(); k != arr.end(); ++k)
    {
        cout << *k << " ";  
    }
    cout << endl;
}
