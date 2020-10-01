#include<stdio.h>
#include<stdlib.h>

void merge(int* arr1, int nums1Size, int m, int* arr2, int nums2Size, int n)
{
    int backup[m+1], i = 0, j = 0, k = 0;

    for(i = 0; i < m; ++i)
    {
        backup[i] = arr1[i];
    }
    i = 0;

    while(i != m && j != n)
    {
        if(backup[i] < arr2[j])
        {
            arr1[k++] = backup[i++];
        }
        else if(backup[i] > arr2[j])
        {
            arr1[k++] = arr2[j++];
        }
        else
        {
            arr1[k++] = backup[i++];
            arr1[k++] = arr2[j++];
        }
    }

    if(i == m)
    {
        while(j < n)
        {
            arr1[k++] = arr2[j++];
        }
    }
    if(j == n)
    {
        while(i < m)
        {
            arr1[k++] = backup[i++];
        }
    }
}

int main()
{
    int numSize1, numSize2, i, n, m;
    
    scanf("%d %d", &n, &m);

    numSize1 = n + m;
    numSize2 = n;

    int arr1[numSize1], arr2[numSize2];

    for(i = 0; i < m; ++i)
    {
        scanf("%d", &arr1[i]);
    }

    for(i = 0; i < n; ++i)
    {
        scanf("%d", &arr2[i]);
    }
    
    merge(arr1, numSize1, m, arr2, numSize2, n);

    for(i = 0; i < numSize1; ++i)
    {
        printf("%d ", arr1[i]);
    }
    
    
}
