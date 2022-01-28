/*
16. 最接近的三数之和
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

 

示例 1：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
示例 2：

输入：nums = [0,0,0], target = 1
输出：0
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i, j, k;
        int target_ = nums[0] + nums[1] + *nums.rbegin();
        int target_tmp;
        if (target_ == target)
            return target_;
        for (i = 0; i < n; i++){
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            k = n - 1;
            for (j = i + 1; j < n && j < k; j++){
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                target_tmp = nums[i] + nums[j] + nums[k];
                if (target_tmp == target)
                    return target;
                if (two_sub(target, target_) > two_sub(target, target_tmp))
                    target_ = target_tmp;
                if (target_tmp > target){
                    k--;
                    j--;
                }
                else {
                    continue;
                }
            }
        }
        return target_;
    }
private:
    int two_sub(int a, int b){
        if (a >= b)
            return a - b;
        else
            return b - a;
    }
};
