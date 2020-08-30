#include <stdio.h>
#include <stdlib.h>

int mark_and_toys(int n, int *arr, int k)
{
    int count = 0, min = __INT_MAX__, i, j, index = 0;

    for(j = 0; j < n; ++j)
    {
        for(i = 0; i < n; ++i)
        {
            if(arr[i] == -1)
                continue;

            if(min > arr[i])
            {
                min = arr[i];
                index = i;
            }
        }

        k -= min;
        if(k >= 0)
        {
            ++count;
            arr[index] = -1;
        }
        else
        {
            break;
        }

        min = __INT_MAX__;
    }
   
    return count;
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

    printf("%d", mark_and_toys(n, arr, k));
}