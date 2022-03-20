#include<stdio.h>
#include<stdlib.h>

int singleNumber(int* nums, int numsSize)
{
    int res = nums[0], i;

    for(i = 1; i < numsSize; ++i)
    {
        res ^= nums[i];
    }
    return res;
}

int main()
{
    int arr[5] = {4,1,2,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", singleNumber(arr, size));
}