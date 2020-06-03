#include <bits/stdc++.h> 
#include <algorithm> 

using namespace std; 

unsigned int count_pairs(unsigned long long int *arr,unsigned int n, unsigned int k)
{
    unsigned int i, count = 0;

    for(i = 0; i < n; ++i)
    {      
        if(binary_search(arr, arr+n, arr[i]+k))
        {
            ++count;
        }
    }

    return count;
}

int main()
{
    unsigned int k, n, i;

    cin >> n >> k;
 
    unsigned long long int arr[n];
    for(i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);

    cout << count_pairs(arr, n, k);
 }