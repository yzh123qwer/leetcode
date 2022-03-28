/*
693. 交替位二进制数
给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。

 

示例 1：

输入：n = 5
输出：true
解释：5 的二进制表示是：101
示例 2：

输入：n = 7
输出：false
解释：7 的二进制表示是：111.
示例 3：

输入：n = 11
输出：false
解释：11 的二进制表示是：1011.
*/
class Solution {
public:
    bool hasAlternatingBits(int n) {
        long i = 1, j = 2;
        bool S;
        if (n % 2 == 1)
            S = true;
        else 
            S = false; // 判断n的第一位是1或0.
        if (S == true){
            while (n != 0){
                if (n % j != 0){
                    n = n - i;
                    i *= 2;
                    j *= 2;
                }
                else 
                    return false;
                if (n % j == 0){
                    i *= 2;
                    j *= 2;
                }
                else    
                    return false;
            }
        }
        else {
            while (n != 0){
                if (n % j == 0){
                    i *= 2;
                    j *= 2;
                }
                else 
                    return false;
                if (n % j != 0){
                    n = n - i;
                    i *= 2;
                    j *= 2;
                }
                else 
                    return false;
            }
        }
        return true;
    }
};
