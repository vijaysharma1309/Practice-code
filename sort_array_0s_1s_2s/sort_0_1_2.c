#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int t, n, i, low, high;
    int *arr = NULL;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        arr = (int *)malloc(n * sizeof(int));
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
    
        low = 0;
        high = n-1;
        for(i = 0; i < n; ++i)
        {
            if(arr[i] == 0)
            {
                if(i == low)
                {
                    ++low;
                    continue;
                }

                swap(&arr[low], &arr[i]);
                ++low;
                --i;
            }
            else if(arr[i] == 2 && i < high)
            {
                swap(&arr[high], &arr[i]);
                --high;
                --i;
            }
        }
        for(i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        free(arr);
    }
}
