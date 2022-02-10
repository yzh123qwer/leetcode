/*
1447. 最简分数
给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。

 

示例 1：

输入：n = 2
输出：["1/2"]
解释："1/2" 是唯一一个分母小于等于 2 的最简分数。
示例 2：

输入：n = 3
输出：["1/2","1/3","2/3"]
示例 3：

输入：n = 4
输出：["1/2","1/3","1/4","2/3","3/4"]
解释："2/4" 不是最简分数，因为它可以化简为 "1/2" 。
示例 4：

输入：n = 1
输出：[]
*/
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        if (n == 1){
            return ans;
        }
        int i, j;
        string temp = "";
        for (i = 2; i <= n; i++){
            ans.push_back(to_string(1) + "/" + to_string(i));
            temp.clear();//分子为1一定是真分数
            for (j = 2; j < i; j++){
                if (__gcd(i ,j) == 1){//__gcd(a, b)可以判断a和b的最大公约数
                    ans.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return ans;
    }
};
