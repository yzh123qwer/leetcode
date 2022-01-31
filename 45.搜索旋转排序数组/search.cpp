/*
33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

 

示例 1：

输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：

输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：

输入：nums = [1], target = 0
输出：-1
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1){
            if (nums[0] == target)
                return 0;
            else 
                return -1;
        }
        if (target == nums[0])
            return 0;
        else if (target > nums[0]){
            for (int i = 1; i < nums.size() && nums[i] >= nums[i - 1]; i++){
                if (nums[i] == target)
                    return i;
            }
            return -1;
        }
        else if (target > nums[nums.size() - 1])//此时target<nums[0]
            return -1;
        else if (target == nums[nums.size() - 1])
            return nums.size() - 1;
        else {
            for (int i = nums.size() - 2; i != 0 && nums[i] <= nums[i + 1]; i--)
                if (nums[i] == target)
                    return i;
            return -1;
        }
    }
};
