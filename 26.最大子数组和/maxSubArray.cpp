/*
53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (max(nums) < 0)
            return max(nums);
        else{
            int ThisSum, MaxSum, j;
            ThisSum = MaxSum = 0;
            for (j = 0; j < nums.size(); j++){
                ThisSum = ThisSum + nums[j];
                if (ThisSum > MaxSum)
                    MaxSum = ThisSum;
                else if (ThisSum < 0)
                    ThisSum = 0;
            }
            return MaxSum;
        }
    }
private:
    int max(vector<int>& nums){
        int a = nums[0];
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] > a)
                a = nums[i];
        return a;
    }
};
