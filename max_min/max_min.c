#include<stdio.h>
#include<stdlib.h>

void merge(unsigned int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    unsigned int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(unsigned int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

unsigned int max_min(unsigned int *arr, int n, int k)
{
    int i, j;
    mergeSort(arr, 0, n-1);
    
    unsigned int val, min = arr[k-1] - arr[0];
    for(i = 1; i <= n-k; ++i)
    {
        val = arr[i + k-1] - arr[i]; 
        if(min > val)
        {
            min = val;
        }
    }

    return min;
}

int main()
{
    int n, i, k;
    scanf("%d %d", &n, &k);
    
    unsigned int arr[n];
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", max_min(arr, n, k));
}
