/*
386. 字典序排数
给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。

你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。

示例 1：

输入：n = 13
输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
示例 2：

输入：n = 2
输出：[1,2]
*/
class Solution {
public:
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        dfs(1, n);
        return ans;
    }
    void dfs(int temp, int n){
        if (temp < n){
            ans.push_back(temp);
            dfs(temp * 10, n);
            if (temp % 10 != 9)
                dfs(temp + 1, n);
            return;
        }
        else if (temp == n){
            ans.push_back(temp);
            return;
        }
        else 
            return;
    }
};
