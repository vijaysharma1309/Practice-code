#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <iterator> 
using namespace std;

int inc_count(int *brr, int d, int mid, int val)
{
    int m = 0, v1 = 0, v2 = 0, count = 0;
    
    for(int i = 0; i < 201; ++i)
    {
        if(brr[i])
        {
            count += brr[i];
        }
        if(count-1 >= mid)
        {
            v1 = i;
            if(count-1 > mid)
            {
                v2 = i;
                break;
            }
            else
            {
                for(int j = i+1; j < 201; ++j)
                {
                    if(brr[j])
                    {
                        v2 = j;
                        break;
                    }
                }
            }
            break;
        }
    }

    if(d % 2)
    {
        if(v2 * 2 <= val)
            return 1;
    }
    else
    {
        m = v1 + v2;
        if(m <= val)
            return 1;
    }

    return 0;
}

int notification_count(vector<int> arr, int n, int d)
{
    int count = 0, mid = (d / 2 - 1);
    int brr[201] = {0};

    for(int i = 0; i < d; ++i)
    {
        brr[arr[i]] += 1;
    }

    for(int i = d; i < n; ++i)
    {
        count += inc_count(brr, d, mid, arr[i]);

        brr[arr[i-d]] -= 1;
        brr[arr[i]] += 1;
    }

    return count;
}

int main()
{
    int n, d, val;
    vector<int> arr;

    cin >> n >> d;
    for(int i = 0; i < n; ++i)
    {
        cin >> val;
        arr.push_back(val);
    }

    cout << notification_count(arr, n, d);
}

