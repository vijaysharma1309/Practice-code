#include<stdio.h>
#include<stdlib.h>

void cavity_map(char **arr, int n)
{
    int i, j;
    for(i = 0; i < n; ++i)
    {
        if(i == 0 || i == (n - 1))
            continue;

        for(j = 0; j < n; ++j)
        {
            if(j == 0 || j == (n - 1))
                continue;

            if((arr[i][j] > arr[i-1][j]) && (arr[i][j] > arr[i+1][j]) && (arr[i][j] > arr[i][j-1]) && (arr[i][j] > arr[i][j+1]))
            {
                arr[i][j] = 'X';
            }
        }
    }

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int i, j, n;

    scanf("%d", &n);
 
    char **arr = (char **)malloc((n) * sizeof(char *)); 
    for (i = 0; i < n; i++)
    {
         arr[i] = (char *)malloc(n * sizeof(char)); 
    }

    for(i = 0; i < n; ++i)
    {
        scanf("%s",arr[i]);
    }

    cavity_map(arr, n);
}
