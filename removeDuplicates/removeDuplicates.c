#include <stdio.h>

void left_rotate(int *arr, int n, int index, int count)
{
    int i, j, temp, last;
    for(j = 0; j < count; ++j)
    {
        last = arr[index];
        for(i = index; i < n - 1; ++i)
        {
            arr[i] = arr[i+1];
        }
        arr[i] = last;
    }
}

int removeDuplicates(int *arr, int n)
{
    int i, j, count = 0, len = n;

    for(i = 0; i < len - 1; ++i)
    {
        count = 0;
        for(j = i+1; j < n; ++j)
        {
            if(arr[i] != arr[j])
                break;
            ++count;               
        }
        if(count)
        {
            left_rotate(arr, n, i, count);
            len = len - count;
        }  
    }
    return len;
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

    printf("%d\n",removeDuplicates(arr, n));

    for(i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}