#include<stdio.h>

int main()
{
    int i, t, n;

    scanf("%d", &t);

    while(t--)
    {
        scanf("%d" ,&n);
        int sum = 0, flag = 0;
        int arr[n];
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        
        int sum_l = 0, sum_r = 0, s = 0;
        
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
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
