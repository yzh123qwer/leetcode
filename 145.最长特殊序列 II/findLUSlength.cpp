/*
522. 最长特殊序列 II
给定字符串列表 strs ，返回其中 最长的特殊序列 。如果最长特殊序列不存在，返回 -1 。

特殊序列 定义如下：该序列为某字符串 独有的子序列（即不能是其他字符串的子序列）。

 s 的 子序列可以通过删去字符串 s 中的某些字符实现。

例如，"abc" 是 "aebdc" 的子序列，因为您可以删除"aebdc"中的下划线字符来得到 "abc" 。"aebdc"的子序列还包括"aebdc"、 "aeb" 和 "" (空字符串)。
 

示例 1：

输入: strs = ["aba","cdc","eae"]
输出: 3
示例 2:

输入: strs = ["aaa","aaa","aa"]
输出: -1
*/
class Solution {
    bool fun(string s1, string s2){ // s1是s2的子序列则返回false，否则返回true
        int i = 0;
        int j = 0;
        while(true){
            if (i == s1.size() && j == s2.size()){
                return false;
            }
            else if (i == s1.size()){
                return false;
            }
            else if (j == s2.size()){
                return true;
            }
            else {
                if (s1[i] != s2[j]){
                    j++;
                }
                else { // s1[i] == s2[j]
                    i++;
                    j++;
                }
            }
        }
        return false; // 并不会执行到这里。
    }
public:
    int findLUSlength(vector<string>& strs) {
        bool S = true;
        int ans = -1;
        for (int i = 0; i < strs.size(); i++){
            S = true;
            for (int ii = 0; ii < strs.size(); ii++){
                if (ii == i)
                    continue;
                if (fun(strs[i], strs[ii]) == false){
                    S = false;
                    break;
                }
            }
            if (S == true && (ans == -1 || ans < strs[i].size()))
                ans = strs[i].size();
        }
        return ans;
    }
};
