#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int n, i, j, count = 0, same = 0;
    int *arr;

    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; ++i) 
    {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; ++i) 
    {
        same = 1;
        for (j = i + 1; j < n; ++j) 
        {
        if (arr[j] > 0) 
        {
            if (arr[i] == arr[j]) 
            {
            same++;
            arr[j] = -1;
            }
        }
        }
        count += same / 2;
    }
    printf("%d", count);
}
