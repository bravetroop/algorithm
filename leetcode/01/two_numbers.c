#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i = 0;
    int j = 0;
    int *result = 0;

    *returnSize = 0;
    result = (int*)malloc(sizeof(int)*2);

    for(i = 0; i < numsSize; ++i)
    {
        for(j = i+1; j < numsSize; ++j)
        {
            if(nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    return result;
}

int main()
{
	int *result = 0;
	int result_size = 0;
	int arr[] = {2, 7, 11, 15};

	result = twoSum(arr, sizeof(arr)/sizeof(int), 9, &result_size);

	free(result);
	return 0;
}
