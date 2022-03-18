#include<stdio.h>
#include<stdlib.h>

int* targetIndices(int* nums, int numsSize, int target, int* returnSize)
{
    int *arr = (int *)malloc(numsSize * sizeof(int));
    int i, count = 0, small = 0;

    for(i = 0;i < numsSize; ++i)
    {
        if(nums[i] < target)
        {
            ++small;
        }
        if(nums[i] == target)
        {
            ++count;
        }
    }

    for(i = 0; i < count; ++i)
    {
        arr[i] = small + i;
    }

    *returnSize = count;

    return arr;
}

int main()
{
    int arr[5] = {1,2,5,2,3};
    int *outArr = NULL;
    int returnSize, i;
    outArr = targetIndices(arr, 5, 2, &returnSize);

    for(i = 0; i < returnSize; ++i) 
    { 
        printf("%d ", outArr[i]);
    }
    
    free(outArr);
}
