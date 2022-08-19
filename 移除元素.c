int removeElement(int* nums, int numsSize, int val)
{
    int* left = nums;
    int* right = nums + numsSize - 1;
    while(left <= right)
    {
        if(*left == val)
        {
            *left = *right;
            right--;
            numsSize--;
        }
        else
        {
            left++;
        }
    }
    return numsSize;
}

