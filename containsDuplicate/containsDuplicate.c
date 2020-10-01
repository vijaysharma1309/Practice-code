#include <stdio.h>
#include <stdbool.h> 

bool containsDuplicate(int *arr, int n)
{
    int i, j, k;

    for(i = 0, j = n-1; i < n; ++i, --j)
    {
        for(k = i+1; k <= j; ++k)
        {
            if(arr[k] == arr[i])
            {
                return 1;
            }
        }
        for(k = j-1; k > i; --k)
        {
            if(arr[k] == arr[j])
            {
                return 1;
            }
        }
    }
    return 0;
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

    if(containsDuplicate(arr, n))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    
}