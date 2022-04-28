/*
905. 按奇偶排序数组
给你一个整数数组 nums，将 nums 中的的所有偶数元素移动到数组的前面，后跟所有奇数元素。

返回满足此条件的 任一数组 作为答案。

 

示例 1：

输入：nums = [3,1,2,4]
输出：[2,4,3,1]
解释：[4,2,3,1]、[2,4,1,3] 和 [4,2,1,3] 也会被视作正确答案。
示例 2：

输入：nums = [0]
输出：[0]
*/
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int i = 0, j = n - 1;
        for (auto ii : nums){
            if (ii % 2 == 0)
                ans[i++] = ii;
            else 
                ans[j--] = ii;
        }
        return ans;
    }
/*
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans;
        vector<int> temp;
        for (auto i : nums){
            if (i % 2 == 0)
                ans.push_back(i);
            else 
                temp.push_back(i);
        }
        for (auto i : temp)
            ans.push_back(i);
        return ans;
    }
    */
};
