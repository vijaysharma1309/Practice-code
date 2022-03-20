#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    if(numsSize == 0)
        return 0;
    
    int i = 0, j = 1, size = 0;
    
    while(j < numsSize)
    {
        if(nums[i] != nums[j] && (j == i+1))
        {
            i++;
        }
        else if(nums[i] != nums[j])
        {
            nums[i+1] = nums[j];
            ++i;
        }
        ++j;
    }
    return i+1;
}

int main()
{
    int n, i;

    int arr[10] = {0,0,1,1,1,2,2,3,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int out = removeDuplicates(arr, size);

    for(i = 0; i < out; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}