#include<stdio.h>
#include<stdlib.h>

#define COLUMN_SIZE             2

int luck_balance(int **arr, int n, int k, int luck)
{
    int i, j, max, index;

    for(j = 0; j < k; ++j)
    {
        max = arr[0][0];
        index = 0;
        for(i = 0; i < n; ++i)
        {
            if(arr[i][1] == 1)
            {
                if(max < arr[i][0])
                {
                    max = arr[i][0];
                    index = i;
                }
            }
        }
        //changing max k luck value to be 0
        arr[index][0] = 0;
    }

    for(i = 0; i < n; ++i)
    {
        if(arr[i][1] == 1 && arr[i][0] != 0)
        {
            //subtracting luck values that are important.
            //multiplied by 2 because I have already added them.
            luck -= arr[i][0] * 2;
        }
    }

    return luck;
}

int main()
{
    int n, i, j, k, luck = 0;
    int **arr = NULL;

    scanf("%d %d", &n, &k);
    
    arr = (int **)malloc(n * sizeof(int *));
    for(i = 0; i < n; ++i)
    {
        arr[i] = (int *)malloc(COLUMN_SIZE * sizeof(int));
    }

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < COLUMN_SIZE; ++j)
        {
            scanf("%d", &arr[i][j]);

            if(j == 0)
            {
                //adding all luck values
                luck += arr[i][0];
            }
        }
    }
    
    printf("%d", luck_balance(arr, n, k, luck));

    free(arr);
}
