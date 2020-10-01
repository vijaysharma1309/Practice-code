#include <stdio.h>

int maxProfit(int *arr, int n)
{
    int i, count = 0, backup = 0;

    for(i = 0; i < n; ++i)
    {
        backup = arr[i];
        while(i < (n - 1) && arr[i] < arr[i+1])
        {
            ++i;
        }

        count += (arr[i] - backup);
    }
    return count;
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