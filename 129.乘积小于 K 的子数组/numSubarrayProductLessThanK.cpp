/*
713. 乘积小于 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 

示例 1：

输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。
示例 2：

输入：nums = [1,2,3], k = 0
输出：0
*/
class Solution {
    int fun(int i, int ii){
        int ans = 0;
        for (int j = ii - i - 1; j != 0; j--)
            ans += j;
        return ans;
    }
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0)
            return 0;
        int ans = 0;
        int temp = 1; // nums.size() >= 1
        int i = 0, j = 0;
        while(i < nums.size() - 1 && j < nums.size()){
            temp = temp * nums[j];
            if (temp < k){
                j++;
            }
            else {
                if (j > i){
                    ans += j - i;
                    temp /= nums[i++];
                    temp /= nums[j];
                }
                else {
                    i++;
                    j = i;
                    temp = 1;
                }
            }
        }
        if (i != nums.size() - 1){ // j == nums.size()
            for (int ii = j - i; ii != 0; ii--)
                ans += ii;
        }
        else {
            if (nums.back() < k)
                ans++;
        }
        return ans;
    }
};
