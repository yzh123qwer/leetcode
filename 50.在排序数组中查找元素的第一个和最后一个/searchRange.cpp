/*
34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ij(2, -1);
        if (nums.size() == 0)
            return ij;
        if (nums.size() == 1){
            if (nums[0] == target){
                ij[0] = 0;
                ij[1] = 0;
                return ij;
            }
            else 
                return ij;
        }
        if (target > nums[nums.size() - 1])
            return ij;
        if (target < nums[0])
            return ij;
        int i, j, mid;
        for (i = 0, j = nums.size() - 1, mid = (i + j) / 2; i < j; mid = (i + j) / 2){
            if (nums[mid] < target){
                if (nums[mid + 1] == target){
                    i = mid + 1;
                    for (j = i; j < nums.size() && nums[j] == target; j++);
                    ij[0] = i;
                    ij[1] = j - 1;
                    return ij;
                }
                else if (nums[mid + 1] > target){
                    return ij;
                }
                else {
                    i = mid + 1;
                    continue;
                }
            }
            else if (nums[mid] > target){
                if (nums[mid - 1] == target){
                    j = mid - 1;
                    for (i = j; i != -1 && nums[i] == target; i--);
                    ij[0] = i + 1;
                    ij[1] = j;
                    return ij;
                }
                else if (nums[mid - 1] < target)
                    return ij;
                else {//nums[mid - 1] > target
                    j = mid - 1;
                    continue;
                }
            }
            else { // nums[mid] == target
                for (i = mid; i != -1 && nums[i] == target; i--);
                for (j = mid; j < nums.size() && nums[j] == target; j++);
                ij[0] = i + 1;
                ij[1] = j - 1;
                return ij;
            }
        }
        return ij;
    }
};
