/*
172. 阶乘后的零
给定一个整数 n ，返回 n! 结果中尾随零的数量。

提示 n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1

 

示例 1：

输入：n = 3
输出：0
解释：3! = 6 ，不含尾随 0
示例 2：

输入：n = 5
输出：1
解释：5! = 120 ，有一个尾随 0
示例 3：

输入：n = 0
输出：0
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int temp;
        for (int i = 1; i <= n; i++){
            if (i % 5 == 0){
                temp = i;
                while (temp % 5 == 0){
                    ans++;
                    temp = temp / 5;
                }
            }
        }
        return ans;
    }
};
