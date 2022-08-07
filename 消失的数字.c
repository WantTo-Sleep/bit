int missingNumber(int* nums, int numsSize)
{
    int* p = (int*)malloc((numsSize + 1) * sizeof(int));
    if(p == NULL)
        return -1;
    int i = 0;
    int size = numsSize;
    while(size--)
    {
        i = nums[size];
        p[i] = i;
    }
    for(i = 0; i <= numsSize; i++)
    {
        if(p[i] != i)
            return i;
    }
    free(p);
    p = NULL;
    return -1;
}
