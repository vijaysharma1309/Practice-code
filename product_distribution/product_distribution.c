#include<stdio.h>
#include<stdlib.h>

void merge(unsigned int arr[], unsigned int l, unsigned int m, unsigned int r) 
{ 
    unsigned int i, j, k; 
    unsigned int n1 = m - l + 1; 
    unsigned int n2 =  r - m; 
  
    /* create temp arrays */
    unsigned int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
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
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(unsigned int arr[], unsigned int l, unsigned int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        unsigned int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int main()
{
    unsigned int m, n, i, j, rem = 0, quo = 0;
    unsigned long long int sum = 0, max_score = 0;
    unsigned int modulo = 1000000007;

    scanf("%d %d", &n, &m);
    
    unsigned int arr[n];
    for(i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
        
    mergeSort(arr, 0, n-1);

    rem = n % m;
    quo = n / m;

    if(rem && quo > 1)
    {
        j = 1;
        for(i = 0; i < (m * quo-1); ++i)
        {
            sum += arr[i];
            if(!((i+1) % m))
            {
                max_score += sum*(j++);
                sum = 0;
            }
        }
        for(i = (m * quo - 1); i < n; ++i)
        {
            sum += arr[i];
        }
        max_score += sum * j;
    }
    else
    {
        j = 1;
        for(i = 0; i < n; ++i)
        {
            sum += arr[i];
            if(!((i+1) % m))
            {
                max_score += sum*(j++);
                sum = 0;
            }
        }
    }
    printf("%lld", max_score % modulo);
}
