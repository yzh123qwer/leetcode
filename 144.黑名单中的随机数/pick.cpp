/*
710. 黑名单中的随机数
给定一个整数 n 和一个 无重复 黑名单整数数组 blacklist 。设计一种算法，从 [0, n - 1] 范围内的任意整数中选取一个 未加入 黑名单 blacklist 的整数。任何在上述范围内且不在黑名单 blacklist 中的整数都应该有 同等的可能性 被返回。

优化你的算法，使它最小化调用语言 内置 随机函数的次数。

实现 Solution 类:

Solution(int n, int[] blacklist) 初始化整数 n 和被加入黑名单 blacklist 的整数
int pick() 返回一个范围为 [0, n - 1] 且不在黑名单 blacklist 中的随机整数
 

示例 1：

输入
["Solution", "pick", "pick", "pick", "pick", "pick", "pick", "pick"]
[[7, [2, 3, 5]], [], [], [], [], [], [], []]
输出
[null, 0, 4, 1, 6, 1, 0, 4]

解释
Solution solution = new Solution(7, [2, 3, 5]);
solution.pick(); // 返回0，任何[0,1,4,6]的整数都可以。注意，对于每一个pick的调用，
                 // 0、1、4和6的返回概率必须相等(即概率为1/4)。
solution.pick(); // 返回 4
solution.pick(); // 返回 1
solution.pick(); // 返回 6
solution.pick(); // 返回 1
solution.pick(); // 返回 0
solution.pick(); // 返回 4
*/
class Solution {
    queue<int> nums;
public:
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> blacklist_hash;
        for (int i = 0; i < blacklist.size(); i++){
            if (blacklist_hash.find(blacklist[i]) == blacklist_hash.end())
                blacklist_hash.insert(blacklist[i]);
        }
        for (int i = 0; i < n; i++){
            if (blacklist_hash.find(i) == blacklist_hash.end())
                nums.push(i);
            if (nums.size() == 10)
                break;
        }
    }
    int pick() {
        int ans = nums.front();
        nums.pop();
        nums.push(ans);
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
