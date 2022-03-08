/*
2055. 蜡烛之间的盘子
给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。

同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] （包含左右端点的字符）。对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。

比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。

 

示例 1:

ex-1

输入：s = "**|**|***|", queries = [[2,5],[5,9]]
输出：[2,3]
解释：
- queries[0] 有两个盘子在蜡烛之间。
- queries[1] 有三个盘子在蜡烛之间。
示例 2:

ex-2

输入：s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
输出：[9,0,0,0,0]
解释：
- queries[0] 有 9 个盘子在蜡烛之间。
- 另一个查询没有盘子在蜡烛之间。
*/
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candle;
        candle.push_back(-1);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '|'){
                candle.push_back(i);
            }
        }
        vector<int> ans;
        if (candle.size() == 1){
            for (int i = 0; i < queries.size(); i++)
                ans.push_back(0);
            return ans;
        }
        candle.push_back(s.size());// 为了处理当最后一个蜡烛右边仍然存在盘子，定义为-1，则会导致误判
        vector<vector<int>> plant(s.size(), vector<int>(2, -2)); // -1已经表示没有蜡烛，-2表示未被定义
        for (int i = 0, j = 0; i < s.size(); i++){
            if (s[i] == '*'){
                plant[i][0] = candle[j];
                plant[i][1] = candle[j + 1];
            }
            else{ // s[i] == '|'
                j++;
            }
        }
        int temp = 0;
        for (auto i : queries){
            temp = 0;
            for (int j = i[0] + 1; j < i[1]; j++){
                if (plant[j][0] >= i[0] && plant[j][1] <= i[1])
                    temp++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
