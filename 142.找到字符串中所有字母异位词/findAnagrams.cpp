/*
438. 找到字符串中所有字母异位词
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
*/
class Solution {
    bool fun(const vector<int>& hash_p) {
        for (int i = 0; i < 26; i++) {
            if (hash_p[i] == 0)
                continue;
            else
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> hash_p(26, 0);
        for (int i = 0; i < p.size(); i++)
            hash_p[p[i] - 'a'] += 1;
        vector<int> ans;
        if (s.size() < p.size())
            return ans;
        for (int i = 0; i < p.size(); i++) {
            hash_p[s[i] - 'a'] -= 1;
        }
        if (fun(hash_p) == true)
            ans.push_back(0);
        for (int i = p.size(); i < s.size(); i++) {
            hash_p[s[i - p.size()] - 'a'] += 1;
            hash_p[s[i] - 'a'] -= 1;
            if (fun(hash_p) == true)
                ans.push_back(i - p.size() + 1);
        }
        return ans;
    }
};
