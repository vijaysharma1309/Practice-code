#include<stdio.h>

int sansaXor(unsigned int *arr, unsigned int *num_count, int n)
{
    int i;
    unsigned int inc = 0, dec = 0, mid1, mid2, xor = 0;
    //logic to count the number of times we have to xor a particular index.
    //ex: the count of n = 9
    //(9) (9+7) (9+7+5) (9+7+5+3) . . .
    if(!(n % 2))
    {
        mid1 = n/2 - 1;
        mid2 = n/2;

        for(i = 0; i < n; ++i)
        {
            if(i <= mid1)
            {
                num_count[i] = n - dec + inc;
                inc = num_count[i];
            }
            else if(i == mid2)
            {
                num_count[i] = num_count[i-1];
            }
            else
            {
                num_count[i] = n - dec + inc;
                inc = num_count[i];
            }
            dec += 2;
        }
    }
    else
    {
        for(i = 0; i < n; ++i)
        {
            num_count[i] = n - dec + inc;
            inc = num_count[i];
            dec += 2 ;
        }
    }
    
    for(i = 0; i < n; ++i)
    {
        //xor only the odd value.
        if(num_count[i] % 2)
        {
            xor ^= arr[i];
        }
    }

    return xor;
}

int main()
{
    int t, n, i;
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        unsigned int arr[n];
        unsigned int num_count[n];
        
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
            num_count[i] = 0;
        }
        
        printf("%d\n", sansaXor(arr, num_count, n));
    }
}

