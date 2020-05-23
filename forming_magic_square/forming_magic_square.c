#include<stdio.h>
#include<stdlib.h>

#define N           3

int check_vertical(int **arr)
{
    int count = 0, ver_sum = 0;

    count += abs(3 - arr[0][1]);
    count += abs(7 - arr[2][1]);

    return count;
}

int check_horizontal(int **arr)
{
    int count = 0;

    count += abs(1 - arr[1][0]);
    count += abs(9 - arr[1][2]);

    return count;
}

int check_diagonals(int **arr)
{
    int count = 0;
    
    count += abs(8 - arr[0][0]);
    count += abs(2 - arr[2][2]);
    count += abs(6 - arr[2][0]);
    count += abs(4 - arr[0][2]);

    return count;
}

void change_matrix(int **arr)
{
    int i, j, l, m;
    int matrix[N][N];
    
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            matrix[i][j] = arr[j][N-1-i];
        }
    }

    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            arr[i][j] = matrix[i][j];
        }
    }
}

void transpose(int **arr)
{
    int i, j, l, m;
    int matrix[N][N];
    
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            matrix[j][i] = arr[i][j];
        }
    }

    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            arr[i][j] = matrix[i][j];
        }
    }
}

int forming_magic_square(int **arr)
{
    int i, j, count = 0, min = 9999;
    int c1 = 0;
    if(arr[1][1] != 5)
    {
        count += abs(5 - arr[1][1]);
        arr[1][1] = 5;
        c1 = count;
    }

    for(i = 0; i <= N; ++i)
    {
        count = 0;

        change_matrix(arr);
        
        count = check_diagonals(arr);
        count += check_vertical(arr);
        count += check_horizontal(arr);
        count += c1;
        if(min > count)
        {
            min = count;
        }

        for(j = 0; j <= N; ++j)
        {
            count = 0;
            transpose(arr);
            
            count += check_diagonals(arr);
            count += check_vertical(arr);
            count += check_horizontal(arr);

            count += c1;
            if(min > count)
            {
                min = count;
            }
        }
    }

    return min;
}

int main()
{
    int i, j;
    int **arr = (int **)malloc(N * sizeof(int *));

    for(i = 0; i < N; ++i)
    {
        arr[i] = (int *)malloc(N * sizeof(int));
        for(j = 0; j < N; ++j)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("%d", forming_magic_square(arr));
}

