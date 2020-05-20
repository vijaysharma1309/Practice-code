#include<stdio.h>

char *balancedSum(int *arr, int n)
{
    int i, sum_l = 0, sum_r = 0, s = 0, flag = 0;
    int sum = 0;
    
    for(i = 0; i < n; ++i)
    {
        sum += arr[i];
    }
    
    for(i = 0; i < n; ++i)
    {
        s += arr[i];
        sum_r = sum - s;
        if(i >= 1)
        {
            sum_l += arr[i-1];
        }
        if(sum_l == sum_r)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    int i, t, n;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d" ,&n);
        int arr[n];
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        printf("%s\n", balancedSum(arr, n));  
    }
}
