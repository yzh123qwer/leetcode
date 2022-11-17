/*
792. 匹配子序列的单词数
给定字符串 s 和字符串数组 words, 返回  words[i] 中是s的子序列的单词个数 。

字符串的 子序列 是从原始字符串中生成的新字符串，可以从中删去一些字符(可以是none)，而不改变其余字符的相对顺序。

例如， “ace” 是 “abcde” 的子序列。
 

示例 1:

输入: s = "abcde", words = ["a","bb","acd","ace"]
输出: 3
解释: 有三个是 s 的子序列的单词: "a", "acd", "ace"。
Example 2:

输入: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
输出: 2
*/
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_set<string> hash_true;
        unordered_set<string> hash_false;
        for (int i = 0; i < words.size(); i++) {
            int s_i = 0;
            if (hash_true.find(words[i]) != hash_true.end()) {
                ans++;
                continue;
            }
            if (hash_false.find(words[i]) != hash_false.end()){
                continue;
            }
            for (int ii = 0; ii < words[i].size(); ii++) {
                if (s_i >= s.size())
                    break;
                if (words[i][ii] == s[s_i]) {
                    s_i++;
                    if (ii == words[i].size() - 1) {
                        ans++;
                        hash_true.insert(words[i]);
                    }
                }
                else {
                    ii--;
                    s_i++;
                }
            }
            if (hash_true.find(words[i]) == hash_true.end()){
                hash_false.insert(words[i]);
            }
        }
        return ans;
    }
};
