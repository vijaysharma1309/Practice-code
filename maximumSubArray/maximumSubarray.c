#include <stdio.h>

int g_max;

int maxElement(int a, int b)
{
    return (a > b ? a : b);
}

int maxSubArray(int* arr, int n)
{
    int max = arr[0], curr = arr[0], i;

    for(i = 1; i < n; ++i)
    {
        curr = maxElement(arr[i], curr + arr[i]);
        max = maxElement(max, curr);
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

    printf("%d\n",maxSubArray(arr, n));
}