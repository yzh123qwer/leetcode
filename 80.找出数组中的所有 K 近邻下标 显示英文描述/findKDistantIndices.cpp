/*
6031. 找出数组中的所有 K 近邻下标 显示英文描述 
通过的用户数6400
尝试过的用户数6713
用户总通过次数6502
用户总提交次数13542
题目难度Easy
给你一个下标从 0 开始的整数数组 nums 和两个整数 key 和 k 。K 近邻下标 是 nums 中的一个下标 i ，并满足至少存在一个下标 j 使得 |i - j| <= k 且 nums[j] == key 。

以列表形式返回按 递增顺序 排序的所有 K 近邻下标。

 

示例 1：

输入：nums = [3,4,9,1,3,9,5], key = 9, k = 1
输出：[1,2,3,4,5,6]
解释：因此，nums[2] == key 且 nums[5] == key 。
- 对下标 0 ，|0 - 2| > k 且 |0 - 5| > k ，所以不存在 j 使得 |0 - j| <= k 且 nums[j] == key 。所以 0 不是一个 K 近邻下标。
- 对下标 1 ，|1 - 2| <= k 且 nums[2] == key ，所以 1 是一个 K 近邻下标。
- 对下标 2 ，|2 - 2| <= k 且 nums[2] == key ，所以 2 是一个 K 近邻下标。
- 对下标 3 ，|3 - 2| <= k 且 nums[2] == key ，所以 3 是一个 K 近邻下标。
- 对下标 4 ，|4 - 5| <= k 且 nums[5] == key ，所以 4 是一个 K 近邻下标。
- 对下标 5 ，|5 - 5| <= k 且 nums[5] == key ，所以 5 是一个 K 近邻下标。
- 对下标 6 ，|6 - 5| <= k 且 nums[5] == key ，所以 6 是一个 K 近邻下标。
因此，按递增顺序返回 [1,2,3,4,5,6] 。 
示例 2：

输入：nums = [2,2,2,2,2], key = 2, k = 2
输出：[0,1,2,3,4]
解释：对 nums 的所有下标 i ，总存在某个下标 j 使得 |i - j| <= k 且 nums[j] == key ，所以每个下标都是一个 K 近邻下标。 
因此，返回 [0,1,2,3,4] 。
*/
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> k_i(nums.size(), 0);
        int m, n;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == key){
                m = i - k;
                n = i + k;
                if (m < 0)
                    m = 0;
                if (n > nums.size() - 1)
                    n = nums.size() - 1;
                for (int j = m; j <= n; j++)
                    k_i[j]++;
            }
        }
        vector<int> ans;
        for (int i = 0; i < k_i.size(); i++){
            if (k_i[i] != 0)
                ans.push_back(i);
        }
        return ans;
    }
};
