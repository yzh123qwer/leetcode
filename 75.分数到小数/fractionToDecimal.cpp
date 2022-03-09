/*
166. 分数到小数
给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以 字符串形式返回小数 。

如果小数部分为循环小数，则将循环的部分括在括号内。

如果存在多个答案，只需返回 任意一个 。

对于所有给定的输入，保证 答案字符串的长度小于 104 。

 

示例 1：

输入：numerator = 1, denominator = 2
输出："0.5"
示例 2：

输入：numerator = 2, denominator = 1
输出："2"
示例 3：

输入：numerator = 2, denominator = 3
输出："0.(6)"
示例 4：

输入：numerator = 4, denominator = 333
输出："0.(012)"
示例 5：

输入：numerator = 1, denominator = 5
输出："0.2"
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";
        bool S;
        long long lnumerator, ldenominator;
        if (numerator > 0 && denominator > 0){
            lnumerator = numerator;
            ldenominator = denominator;
            S = true;
        }
        else if (numerator < 0 && denominator < 0){
            lnumerator = numerator;
            lnumerator = -lnumerator;
            ldenominator = denominator;
            ldenominator = -ldenominator;
            S = true;
        }
        else if (numerator > 0){
            lnumerator = numerator;
            ldenominator = -denominator;
            S = false;
        }
        else {
            lnumerator = numerator;
            lnumerator = -lnumerator;
            ldenominator = denominator;
            S = false;
        }
        if (lnumerator % ldenominator == 0){
            if (S == true)
                return to_string(lnumerator / ldenominator);
            else
                return "-" + to_string(lnumerator / ldenominator);
        }
        string ans;
        if (lnumerator > ldenominator){
            ans = ans + to_string(lnumerator / ldenominator);
            lnumerator = lnumerator - (lnumerator / ldenominator) * ldenominator;
            ans.push_back('.');
        }
        else { //lnumerator < ldenominator
            ans = ans + "0.";
        }
        vector<unordered_map<int, int>> a(10); 
        // a用于存放商为0-9的余数和位置
        string double_nums;
        int res, rem; // 商和余数
        for (lnumerator = lnumerator * 10 ; ; lnumerator = lnumerator * 10){
            if (lnumerator % ldenominator == 0){
                double_nums += to_string(lnumerator / ldenominator);
                ans = ans + double_nums;
                if (S == true)
                    return ans;
                else {
                    ans = "-" + ans;
                    return ans;
                }
            }
            res = lnumerator / ldenominator;
            rem = lnumerator % ldenominator;
            double_nums += to_string(res);
            if (a[res].find(rem) == a[res].end()){ // 没找到
                a[res].insert(make_pair(rem, double_nums.size() - 1));
                lnumerator = lnumerator - res * ldenominator;
            }
            else { //找到
                for (int i = a[res].find(rem)->second, j = 0; j < i; j++)
                    ans.push_back(double_nums[j]);
                ans.push_back('(');
                for (int i = a[res].find(rem)->second; i < double_nums.size() - 1; i++)
                    ans.push_back(double_nums[i]);
                ans.push_back(')');
                if (S == true)
                    return ans;
                else 
                    return "-" + ans;
            }
        }
    }
};
