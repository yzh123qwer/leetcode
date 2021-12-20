//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    if (nums2Size == 0)
    {
        if (nums1Size % 2 == 0)
            return (double)(nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) / 2;
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
                return (double)(nums2[(nums1Size + nums2Size) / 2 - 1 - nums1Size] + nums2[(nums1Size + nums2Size) / 2 - nums1Size]) / 2;
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
                if (m == nums1Size)
                    n = n + 1;
                else if (n == nums2Size)
                    m = m + 1;
                else if (nums1[m] <= nums2[n])
                    m = m + 1;
                else
                    n = n + 1;
            }
            if (m == nums1Size)
                return (double)(nums2[n] + nums2[n + 1]) / 2;
            else if (n == nums2Size)
                return (double)(nums1[m] + nums1[m + 1]) / 2;
            else if (m == nums1Size - 1)
                {
                    if (nums1[m] <= nums2[n + 1])
                        return (double)(nums1[m] + nums2[n]) / 2;
                    else
                        return (double)(nums2[n] + nums2[n + 1]) / 2;
                }
            else if (n == nums2Size - 1)
                {
                    if (nums2[n] < nums1[m + 1])
                        return (double)(nums2[n] + nums1[m]) / 2;
                    else
                        return (double)(nums1[m + 1] + nums1[m]) / 2;
                }
            else
            {
                if (nums1[m] == nums2[n])
                    return (double)(nums1[m]);
                else if (nums1[m] > nums2[n])
                {
                    if(nums1[m] >= nums2[n + 1])
                        return (double)(nums2[n] + nums2[n + 1]) / 2;
                    else
                        return (double)(nums1[m] + nums2[n]) / 2;
                }
                else
                {
                    if (nums2[n] >= nums1[m + 1])
                        return (double)(nums1[m] + nums1[m + 1]) / 2;
                    else
                        return (double)(nums1[m] + nums2[n]) / 2;
                }
            }
        }
        else
        {
            for (i = 0; i < (nums1Size + nums2Size) / 2; i++)
            {
                if (m == nums1Size)
                    n = n + 1;
                else if (n == nums2Size)
                    m = m + 1;
                else if (nums1[m] <= nums2[n])
                    m = m + 1;
                else
                    n = n + 1;
            }
            if (m == nums1Size)
                return (double)nums2[n];
            else if (n == nums2Size)
                return (double)nums1[m];
            else if (nums1[m] <= nums2[n])
                return (double)nums1[m];
            else
                return (double)nums2[n];
        }
    }
}
