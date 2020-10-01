#include <stdio.h>

int maxProfit(int *arr, int n)
{
    int i, j, val, max = 0;
    for(i = 0; i < n - 1; ++i)
    {
        for(j = i+1; j < n; ++j)
        {
            val = arr[j] - arr[i];
            if(max < val && val > 0)
            {
                max = val;
            }
        }
    }
    return max;
}

int main()
{
    int n, i;

    scanf("%d", &n);

    int arr[n]; 
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d\n",maxProfit(arr, n));
}