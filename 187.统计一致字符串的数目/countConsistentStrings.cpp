/*
1684. 统计一致字符串的数目
给你一个由不同字符组成的字符串 allowed 和一个字符串数组 words 。如果一个字符串的每一个字符都在 allowed 中，就称这个字符串是 一致字符串 。

请你返回 words 数组中 一致字符串 的数目。

示例 1：

输入：allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
输出：2
解释：字符串 "aaab" 和 "baa" 都是一致字符串，因为它们只包含字符 'a' 和 'b' 。
示例 2：

输入：allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
输出：7
解释：所有字符串都是一致的。
示例 3：

输入：allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
输出：4
解释：字符串 "cc"，"acd"，"ac" 和 "d" 是一致字符串。
*/
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> hash;
        for (int i = 0; i < allowed.size(); i++){
            if (hash.find(allowed[i]) == hash.end())
                hash.insert(allowed[i]);
        }
        int ret = 0;
        bool S = true;
        for (int i = 0; i < words.size(); i++){
            S = true;
            for (int ii = 0; ii < words[i].size(); ii++){
                if (hash.find(words[i][ii]) == hash.end()){
                    S = false;
                    break;
                }
            }
            if (S == true)
                ret++;
        }
        return ret;
    }
};
