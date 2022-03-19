#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool monotonic_inc(int *nums, int numsSize)
{
    int i;
    bool mono = true;

    if(numsSize == 1)
        return true;
    
    for(i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] > nums[i+1])
        {
            mono = false;
            break;
        }
    }

    return mono;
}

bool monotonic_dec(int *nums, int numsSize)
{
    int i;
    bool mono = true;

    if(numsSize == 1)
        return true;
    
    for(i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] < nums[i+1])
        {
            mono = false;
            break;
        }
    }

    return mono;
}

bool isMonotonic(int* nums, int numsSize)
{
    bool mono_inc = false, mono_dec = false;
    mono_inc = monotonic_inc(nums, numsSize);
    mono_dec = monotonic_dec(nums, numsSize);

    return (mono_inc || mono_dec);
}

int main()
{
    int arr[5] = {1,2,2,3, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("%d\n", isMonotonic(arr, size));   
}