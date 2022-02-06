/*
81. 搜索旋转排序数组 II
已知存在一个按非降序排列的整数数组 nums ，数组中的值不必互不相同。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转 ，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,4,4,5,6,6,7] 在下标 5 处经旋转后可能变为 [4,5,6,6,7,0,1,2,4,4] 。

给你 旋转后 的数组 nums 和一个整数 target ，请你编写一个函数来判断给定的目标值是否存在于数组中。如果 nums 中存在这个目标值 target ，则返回 true ，否则返回 false 。

你必须尽可能减少整个操作步骤。

 

示例 1：

输入：nums = [2,5,6,0,0,1,2], target = 0
输出：true
示例 2：

输入：nums = [2,5,6,0,0,1,2], target = 3
输出：false
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return false;
        if (n == 1){
            if (nums[0] == target)
                return true;
            else 
                return false;
        }
        int i, j , mid;
        for (i = 0, j = n - 1, mid = (i + j) / 2 ; ; mid = (i + j) /2){
            if (nums[i] < nums[mid]){
                if (target == nums[i])
                    return true;
                else if (target == nums[mid])
                    return true;
                else if (target > nums[i] && target < nums[mid]){
                    for (j = mid - 1, mid = (i + j) / 2; ; mid = (i + j) / 2){
                        if (target > nums[mid]){
                            if (target == nums[mid + 1])
                                return true;
                            else if (target > nums[mid + 1])
                                i = mid + 1;
                            else //target < nums[mid + 1]
                                return false;
                        }
                        else if (target < nums[mid]){
                            if (target == nums[mid - 1])
                                return true;
                            else if (target > nums[mid - 1])
                                return false;
                            else 
                                j = mid - 1;
                        }
                        else 
                            return true;
                    }
                }
                else //target可能在后半段
                    i = mid + 1;
            }
            else if (nums[i] > nums[mid]){
                if (target == nums[j])
                    return true;
                else if (target == nums[mid])
                    return true;
                else if (target > nums[mid] && target < nums[j]){
                    for (i = mid + 1, mid = (i + j) / 2; ; mid = (i + j) / 2){
                        if (target > nums[mid]){
                            if (target == nums[mid + 1])
                                return true;
                            else if (target > nums[mid + 1])
                                i = mid + 1;
                            else //target < nums[mid + 1]
                                return false;
                        }
                        else if (target < nums[mid]){
                            if (target == nums[mid - 1])
                                return true;
                            else if (target > nums[mid - 1])
                                return false;
                            else 
                                j = mid - 1;
                        }
                        else 
                            return true;
                    }
                }
                else 
                    j = mid - 1;
            }
            else {//nums[i] == nums[mid]
                if (target == nums[i])
                    return true;
                else {
                    for (i = i + 1; i < n; i++)
                        if (target == nums[i])
                            return true;
                    return false;
                }
            }
        }
    }
};
