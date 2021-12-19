double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (nums2Size == 0)
    {
        if (nums1Size % 2 == 0)
            return (double)(nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]);
        else
            return (double)nums1[nums1Size / 2];
    }
    else if (nums1Size == 0)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    else if (nums1[nums1Size - 1] <= nums2[0])
    {
        if ((nums1Size + nums2Size) % 2 == 1)
        {
            if (nums1Size > nums2Size)
                return (double)nums1[(nums1Size + nums2Size) / 2];
            else 
                return (double)nums2[(nums1Size + nums2Size) / 2 - nums1Size];
        }
        else
        {
            if (nums1Size == nums2Size)
                return (double)(nums1[nums1Size - 1] + nums2[0]) / 2;
            else if (nums1Size > nums2Size)
                return (double)(nums1[(nums1Size + nums2Size) / 2 - 1] + nums1[(nums1Size + nums2Size) / 2]) / 2;
            else
                return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
        }
    }
    else if (nums2[nums2Size - 1] <= nums1[0])
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    else
    {
        int m = 0, n = 0, i;
        if ((nums1Size + nums2Size) % 2 == 0)
        {
            for (i = 0; i < (nums1Size + nums2Size) / 2 - 1; i++)
            {
                if (nums1[m] >= nums2[n])
                    m = m + 1;
                else
                    n = n + 1;
            }
            if (nums1[m] == nums2[n])
                return (double)nums1[m];
            else if (nums1[m] < nums2[n])
            {
                if (m == nums1Size - 1)
                    return (double)(nums2[n] + nums2[n + 1]) / 2;
                else if (n == nums2Size - 1)
                    return (double)(nums1[m] + nums1[m + 1]) / 2;
                else
                {
                    if (nums1[m + 1] <= nums2[n + 1])
                        return (double)(nums2[n] + nums2[n + 1]) / 2;
                    else
                        return (double)(nums2[n] + nums1[m + 1]) / 2;
                }
            }
            else
            {
                if (m == nums1Size - 1)
                    return (double)(nums2[n] + nums2[n + 1]) / 2;
                else if (n == nums2Size - 1)
                    return (double)(nums1[m] + nums1[m + 1]) / 2;
                else
                {
                    if (nums1[m + 1] <= nums2[n + 1])
                        return (double)(nums2[n + 1] + nums1[m]);
                    else
                        return (double)(nums1[m] + nums1[m + 1]);
                }
            }
        }
        else
        {
            for (i = 0; i < (nums1Size + nums2Size) / 2; i++)
            {
                if (nums1[m] <= nums2[n])
                    m = m + 1;
                else
                    n = n + 1;
            }
            if (nums1[m] <= nums2[n])
                return (double)nums1[m];
            else
                return (double)nums2[n];
        }
    }
}
