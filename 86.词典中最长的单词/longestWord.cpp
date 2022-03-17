/*
720. 词典中最长的单词
给出一个字符串数组 words 组成的一本英语词典。返回 words 中最长的一个单词，该单词是由 words 词典中其他单词逐步添加一个字母组成。

若其中有多个可行的答案，则返回答案中字典序最小的单词。若无答案，则返回空字符串。

 

示例 1：

输入：words = ["w","wo","wor","worl", "world"]
输出："world"
解释： 单词"world"可由"w", "wo", "wor", 和 "worl"逐步添加一个字母组成。
示例 2：

输入：words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
输出："apple"
解释："apply" 和 "apple" 都能由词典中的单词组成。但是 "apple" 的字典序小于 "apply" 
*/
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() < b.size();
            }
            else {
                return a > b;
            }
            });
        unordered_set<string> hash;
        hash.insert("");
        int str_nums = 1;
        string temp;
        string ans = "";
        int ans_nums = 0;
        for (int i = 0; i < words.size();i++){
            if (words[i].size() == str_nums){
                temp = words[i];
                temp.pop_back();
                if  (hash.find(temp) == hash.end()){
                    continue;
                }
                else {
                    hash.insert(words[i]);
                    if (words[i].size() > ans.size()){
                        ans = words[i];
                    }
                    else if (words[i].size() < ans.size())
                        continue;
                    else {
                        if (comstr(words[i], ans)){
                            ans = words[i];
                        }
                    }
                }
            }
            else if(words[i].size() == str_nums + 1){
                i--;
                str_nums++;
                continue;
            }
            else 
                break;
        }
        return ans;
    }
    bool comstr(string s1, string s2){
        int min_str = s1.size();
        if (s2.size() < min_str)
            min_str = s2.size();
        for (int i = 0; i < min_str; i++){
            if (s1[i] < s2[i])
                return true;
            else if (s1[i] > s2[i])
                return false;
            else 
                continue;
        }
        if (min_str == s1.size())
            return true;
        else 
            return false;
    }
};
