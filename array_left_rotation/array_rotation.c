#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b)
{
    int max, min, q;
    if(a > b)
    {
        max = a;
        min = b;
    }
    else
    {
        max = b;
        min = a;
    }
    
    while(a != 0)
    {
        q = max / min;
        a = max - q*min;
        max = min;
        if(a != 0)
            min = a;
    }
    return min;
}

int main()
{
    int n, k, m, i, j, t1, t2, z;
    
    scanf("%d %d", &n, &k);
    
    int *arr = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    
    k = k % n;
    m = gcd(n,k);

    for(i = 0; i < m; ++i)
    {
        if(m == 1)
        {
            z = 0;
            int arr2[k];
            for(j = 0; j < k; ++j)
            {
                arr2[j] = arr[j];
            }
            for(j = k; j < n; ++j)
            {
                arr[j-k] = arr[j];
            }
            for(j = n-k; j < n; ++j)
            {
                arr[j] = arr2[z++];
            }
        }
        else
        {
            t2 = arr[i];
            for(j = i; j < n; j = j+m)
            {
                t1 = arr[j];
                if(j+m < n)
                    arr[j] = arr[j+m];
            }
            arr[j-m] = t2;
        }
    }

    for(i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
}
