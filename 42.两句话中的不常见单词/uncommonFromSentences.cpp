/*
884. 两句话中的不常见单词
句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。

如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。

给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。

 

示例 1：

输入：s1 = "this apple is sweet", s2 = "this apple is sour"
输出：["sweet","sour"]
示例 2：

输入：s1 = "apple apple", s2 = "banana"
输出：["banana"]
*/
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> A;
        unordered_map<string, int>::iterator H;
        vector<string> words1 = getWords(s1);
        vector<string> words2 = getWords(s2);
        pair<string, int> a;
        a.second = 1;
        for (string tmp : words1) {
            if (A.find(tmp) == A.end()) {
                a.first = tmp;
                A.insert(a);
            }
            else //哈希表中已经有该单词
                A.find(tmp)->second += 1;
        }
        for (string tmp : words2) {
            if (A.find(tmp) == A.end()) {
                a.first = tmp;
                A.insert(a);
            }
            else
                A.find(tmp)->second += 1;
        }
        vector<string> S;
        for (H = A.begin(); H != A.end(); H++) {
            if (H->second == 1)
                S.push_back(H->first);
        }
        for (string o : S) {
            cout << o << "   ";
        }
        return S;
    }
private:
    vector<string> getWords(string s) {
        vector<string> words;
        string tmp;
        int i, j;
        for (i = j = 0; i != s.size(); i++) {
            if (s[i] == ' ') {
                tmp = s.substr(j, i - j);
                j = i + 1;//假定所有单词之间只有一个空格
                words.push_back(tmp);
            }
        }
        tmp = s.substr(j, i - j);
        words.push_back(tmp);
        return words;
    }
};
