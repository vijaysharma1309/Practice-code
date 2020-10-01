#include <stdio.h>

int missingNumber(int *arr, int n)
{
    int i, max = 0, min = 0xFFFFFF, sum = 0, num = 0;

    for(i = 0; i < n; ++i)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }

        if(min > arr[i])
        {
            min = arr[i];
        }

        sum += arr[i];
    }
    
    if(min != 0)
        return 0;

    if(max == (i-1))
        return i;

    num = ((n + 1) * (min + max)) / 2 - sum;  // sum of Arithmatic progression ( sum = n/2(a+l) )

    return num;
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

    printf("%d\n",missingNumber(arr, n));
}