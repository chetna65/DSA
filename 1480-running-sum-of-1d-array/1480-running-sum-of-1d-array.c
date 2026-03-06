/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) 
{
    int sum = 0;
    int *runningSum = (int*)malloc(numsSize * sizeof(int));


    for(int i=0; i<numsSize; i++)
    {
        sum = sum + nums[i];
        runningSum[i] = sum;
    }

    *returnSize = numsSize;

    return runningSum;
}