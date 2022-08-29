/*
6160. 和有限的最长子序列
给你一个长度为 n 的整数数组 nums ，和一个长度为 m 的整数数组 queries 。

返回一个长度为 m 的数组 answer ，其中 answer[i] 是 nums 中 元素之和小于等于 queries[i] 的 子序列 的 最大 长度  。

子序列 是由一个数组删除某些元素（也可以不删除）但不改变剩余元素顺序得到的一个数组。

 

示例 1：

输入：nums = [4,5,2,1], queries = [3,10,21]
输出：[2,3,4]
解释：queries 对应的 answer 如下：
- 子序列 [2,1] 的和小于或等于 3 。可以证明满足题目要求的子序列的最大长度是 2 ，所以 answer[0] = 2 。
- 子序列 [4,5,1] 的和小于或等于 10 。可以证明满足题目要求的子序列的最大长度是 3 ，所以 answer[1] = 3 。
- 子序列 [4,5,2,1] 的和小于或等于 21 。可以证明满足题目要求的子序列的最大长度是 4 ，所以 answer[2] = 4 。
示例 2：

输入：nums = [2,3,4,5], queries = [1]
输出：[0]
解释：空子序列是唯一一个满足元素和小于或等于 1 的子序列，所以 answer[0] = 0 。
*/
class Solution1 {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        unordered_map<int, list<int>> hash;
        list<int> temp;
        int ii = 0;
        int sum = 0;
        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            if (hash.find(queries[i]) == hash.end()) {
                temp.insert(temp.begin(), i);
                hash.insert(make_pair(queries[i], temp));
                temp.clear();
            }
            else {
                hash.find(queries[i])->second.insert(hash.find(queries[i])->second.begin(), i);
            }
        }
        sort(queries.begin(), queries.end());
        for (int i = 0; i < queries.size(); i++) {
            if (sum <= queries[i]) {
                while (sum <= queries[i] && ii < nums.size())
                    sum = sum + nums[ii++];
                if (sum > queries[i]) {
                    for (list<int>::iterator it = hash.find(queries[i])->second.begin(); it != hash.find(queries[i])->second.end(); it++) {
                        ans[*it] = ii - 1;
                    }
                }
                else {
                    for (list<int>::iterator it = hash.find(queries[i])->second.begin(); it != hash.find(queries[i])->second.end(); it++) {
                        ans[*it] = ii;
                    }
                }
            }
            else {
                
                for (list<int>::iterator it = hash.find(queries[i])->second.begin(); it != hash.find(queries[i])->second.end(); it++) {
                    ans[*it] = ii - 1;
                }
            }
        }
        return ans;
    }
};
