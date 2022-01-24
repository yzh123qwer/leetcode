/*
5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
示例 3：

输入：s = "a"
输出："a"
示例 4：

输入：s = "ac"
输出："a"
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<int>> pi (len, vector<int>(len));
        int i, begin, last;
        for (i = 0; i < len; i++){
            pi[i][i] = true;//规定单个字符均为回文子串，记为真
            for (begin = i - 1, last = i + 1; begin != -1 && last != len; begin--, last++){
                if (s[begin] == s[last])
                    pi[begin][last] = true;
                else{
                    pi[begin][last] = false;
                    for ( ; begin != -1 && last != len; begin--, last++)
                        pi[begin][last] = false;
                    break;
                }
            }
        }
        for (i = 0; i < len - 1; i++){
            if (s[i] == s[i + 1]){
                pi[i][i + 1] = true;
                for (begin = i - 1, last = i + 2; begin != -1 && last != len; begin--, last++){
                    if (s[begin] == s[last])
                        pi[begin][last] = true;
                    else{
                        pi[begin][last] = false;
                        for ( ; begin != -1 && last != len; begin--, last++)
                            pi[begin][last] = false;
                        break;
                    }
                }
            }
            else{
                pi[i][i + 1] = false;
                for (begin = i - 1, last = i + 2; begin != -1 && last != len; begin--, last++)
                    pi[begin][last] = false;
            }
        }
        int max_len;
        for (max_len = len; max_len != 1; max_len--){
            for (i = 0; i + max_len <= len; i++){
                if (pi[i][i + max_len - 1] == true)
                    return s.substr(i, max_len);
            }
        }
        return s.substr(0, 1);
    }
};
