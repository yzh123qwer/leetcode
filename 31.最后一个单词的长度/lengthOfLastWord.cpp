/*
58. 最后一个单词的长度
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

 

示例 1：

输入：s = "Hello World"
输出：5
示例 2：

输入：s = "   fly me   to   the moon  "
输出：4
示例 3：

输入：s = "luffy is still joyboy"
输出：6
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        int last;
        for (last = s.size() - 1; last != -1 && s[last] == ' '; last--);
        int nums;
        for (nums = 1 ; last != -1 && s[last] != ' '; last--, nums++);
        return nums - 1;
    }
};
