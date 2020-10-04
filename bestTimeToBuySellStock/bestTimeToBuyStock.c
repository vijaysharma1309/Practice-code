#include <stdio.h>

int maxProfit(int *arr, int n)
{
    int i, max = 0, min = __INT_MAX__;
    
    for(i = 0; i < n; ++i)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
        else if((arr[i] - min) > max)
        {
            max = arr[i] - min;
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