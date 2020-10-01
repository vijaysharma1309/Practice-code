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

void rotate(int* arr, int n, int k)
{
    int juggling_num, i, j, backup, z;

    k = k % n;

    if(n == 1 || k == 0)
    {
        return;
    }

    juggling_num = gcd(n,k);

    if(juggling_num != 1)
    {
        if(k < n/2)
        {
            //right rotation
            for(i = 0; i < juggling_num; ++i)
            {
                backup = arr[n - 1 - i];
                for(j = n - 1 - i; j >= i; j = j - juggling_num)
                {
                    if(j - juggling_num >= 0)
                        arr[j] = arr[j - juggling_num];
                }
                arr[juggling_num - 1 - i] = backup;
            }
        }
        else
        {
            //left rotation
            for(i = 0; i < juggling_num; ++i)
            {
                backup = arr[i];
                for(j = i; j < n; j = j + juggling_num)
                {
                    if(j + juggling_num < n)
                        arr[j] = arr[j + juggling_num];
                }
                arr[j - juggling_num] = backup;
            }
        }
    }
    else
    {
        z = 0;
        int arr2[k];
        for(j = n - k; j < n; ++j)
        {
            arr2[z++] = arr[j];
        }
        
        for(j = n - k - 1; j >= 0; --j)
        {
            arr[j+k] = arr[j];
        }

        z = 0;
        for(j = 0; j < k; ++j)
        {
            arr[j] = arr2[z++];
        }   
    }
}

int main()
{
    int n, k, i;
    
    scanf("%d %d", &n, &k);
    
    int *arr = (int *)malloc(n * sizeof(int));
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    
    rotate(arr, n, k);

    for(i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }

    free(arr);
}
