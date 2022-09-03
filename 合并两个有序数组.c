void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    --m, --n;
    while (m >= 0 && n >= 0)
    {
        if (nums1[m] < nums2[n])
        {
            nums1[--nums1Size] = nums2[n];
            --n;
        }
        else
        {
            nums1[--nums1Size] = nums1[m];
            --m;
        }
    }
    while (n >= 0)
    {
        nums1[--nums1Size] = nums2[n--];
    }
}
