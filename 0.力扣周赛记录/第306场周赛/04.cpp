/*
2376. 统计特殊整数
如果一个正整数每一个数位都是 互不相同 的，我们称它是 特殊整数 。

给你一个 正 整数 n ，请你返回区间 [1, n] 之间特殊整数的数目。

示例 1：

输入：n = 20
输出：19
解释：1 到 20 之间所有整数除了 11 以外都是特殊整数。所以总共有 19 个特殊整数。
示例 2：

输入：n = 5
输出：5
解释：1 到 5 所有整数都是特殊整数。
示例 3：

输入：n = 135
输出：110
解释：从 1 到 135 总共有 110 个整数是特殊整数。
不特殊的部分数字为：22 ，114 和 131 。
*/
class Solution4 {
    bool fun(int i) {
        vector<int> index(10, 0);
        int temp = 0;
        while (i != 0) {
            temp = i % 10;
            if (index[temp] == 0) {
                index[temp] = 1;
            }
            else
                return false;
            i = i / 10;
        }
        return true;
    }
public:
    int countSpecialNumbers(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (fun(i) == true)
                ans++;
        }
        return ans;
    }
};
