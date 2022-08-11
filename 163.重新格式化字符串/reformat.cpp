/*
1417. 重新格式化字符串
给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。

请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。

请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。

 

示例 1：

输入：s = "a0b1c2"
输出："0a1b2c"
解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
示例 2：

输入：s = "leetcode"
输出：""
解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
示例 3：

输入：s = "1229857369"
输出：""
解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
示例 4：

输入：s = "covid2019"
输出："c2o0v1i9d"
示例 5：

输入：s = "ab123"
输出："1a2b3"
*/
class Solution {
public:
    string reformat(string s) {
        if (s.size() == 1)
            return s;
        string s_nums;
        string s_s;
        for (int i = 0; i < s.size(); i++){
            if (s[i] <= '9' && s[i] >= '0')
                s_nums.push_back(s[i]);
            else 
                s_s.push_back(s[i]);
        }
        if (s_nums.size() > s_s.size()){
            if (s_nums.size() - s_s.size() > 1)
                return "";
            string ans;
            for (int i = 0; ; i++){
                ans.push_back(s_nums[i]);
                ans.push_back(s_s[i]);
                if (i == s_s.size() - 1){
                    ans.push_back(s_nums[i + 1]);
                    break;
                }
            }
            
            return ans;
        }
        else if (s_nums.size() < s_s.size()){
            if (s_s.size() - s_nums.size() > 1)
                return "";
            string ans;
            for (int i = 0; ; i++){
                ans.push_back(s_s[i]);
                ans.push_back(s_nums[i]);
                if (i == s_nums.size() - 1){
                    ans.push_back(s_s[i + 1]);
                    break;
                }
            }
            return ans;
        }
        else {
            string ans;
            for (int i = 0; i < s_s.size(); i++){
                ans.push_back(s_nums[i]);
                ans.push_back(s_s[i]);
            }
            return ans;
        }
    }
};
