/*
316. 去除重复字母
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

 

示例 1：

输入：s = "bcabc"
输出："abc"
示例 2：

输入：s = "cbacdcbc"
输出："acdb"
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stack;
        vector<int> s_nums(26, 0), stack_nums(26, 0);//字符串s中字母出现次数，stack中字母出现次数
        for (char i : s)
            s_nums[i - 'a'] += 1;
        for (char i : s){
            s_nums[i - 'a']--;
            if (stack == ""){
                stack_nums[i - 'a']++;
                stack.push_back(i);
            }
            else {
                if (i > stack.back()){
                    if (stack_nums[i - 'a'] == 0){
                        stack.push_back(i);
                        stack_nums[i - 'a']++;
                    }
                    else
                        continue;
                }
                else if (i < stack.back()){
                    if (stack_nums[i - 'a'] != 0)
                        continue;
                    for ( ; stack != "" && (stack.back() > i && s_nums[stack.back() - 'a'] != 0); ){
                        stack_nums[stack.back() - 'a']--;
                        stack.pop_back();
                    }
                    stack.push_back(i);
                    stack_nums[i - 'a']++;
                }
                else // i == stack.back()
                    continue;
            }
        }
        return stack;
    }
};
