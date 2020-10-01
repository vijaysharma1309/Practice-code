#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes(int *arr, int n)
{
    int i = 0;  //index of zero
    int j = 0;  //index of non-zero

    while(i < n && j < n)
    {
        while(i < n && arr[i] != 0)
        {
            ++i;
            j = i + 1;
        }
        while(j < n && arr[j] == 0)
        {
            ++j;
        }

        if(i >= n || j >= n)
            return;

        swap(&arr[i], &arr[j]);
    }
}   

int main()
{
    int n, i;

    scanf("%d", &n);

    int arr[n]; 
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    moveZeroes(arr, n);

    for(i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
}
