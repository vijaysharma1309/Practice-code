#include<stdio.h>
#include<stdlib.h>

int searchInsert(int* nums, int numsSize, int target)
{
    int start = 0, end = numsSize - 1; 
    
    while (start <= end)
    {
        int mid = start + (end- start )/2;

        if (nums[mid] == target)
           return mid;
        if (nums[mid] < target)
           start = mid + 1;
        else
           end = mid - 1;
   }

   return start;
}

int main()
{
    int arr[4] = {1,3,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", searchInsert(arr, size, 7));
}