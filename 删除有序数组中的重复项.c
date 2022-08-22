int removeDuplicates(int* nums, int numsSize)
{
    int* p = nums;
    int* end = nums + numsSize;
    int* temp = nums;
    while(p + 1 < end)
    {
        while((p + 1) < end && *p == *(p + 1))
        {
            ++p;
            --numsSize;
        }
        *temp++ = *p++;
        if(p + 1 == end)
        {
            *temp = *p;
            if(*temp == *(temp - 1))
                --numsSize;
        }
    }
    return numsSize;
}
