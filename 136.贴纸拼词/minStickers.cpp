/*
691. 贴纸拼词
我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。

您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们。如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。

返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。

注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的，并且 target 被选择为两个随机单词的连接。

 

示例 1：

输入： stickers = ["with","example","science"], target = "thehat"
输出：3
解释：
我们可以使用 2 个 "with" 贴纸，和 1 个 "example" 贴纸。
把贴纸上的字母剪下来并重新排列后，就可以形成目标 “thehat“ 了。
此外，这是形成目标字符串所需的最小贴纸数量。
示例 2:

输入：stickers = ["notice","possible"], target = "basicbasic"
输出：-1
解释：我们不能通过剪切给定贴纸的字母来形成目标“basicbasic”。
*/
class Solution {
    void _erase_hash_t(unordered_map<char, int> &hash_t) {
        vector<unordered_map<char, int>::iterator> v_erase;
        for (unordered_map<char, int>::iterator i = hash_t.begin(); i != hash_t.end(); i++) {
            if (i->second <= 0)
                v_erase.push_back(i);
        }
        for (auto i : v_erase)
            hash_t.erase(i);
        return;
    }
    int str1_str2(string s1, string s2) {
        unordered_map<char, int> hash;
        for (auto i : s2) {
            if (hash.find(i) == hash.end())
                hash.insert(make_pair(i, 1));
            else
                hash.find(i)->second += 1;
        }
        int ans = 0;
        for (auto i : s1) {
            if (hash.find(i) != hash.end() && hash.find(i)->second > 0) {
                ans++;
                hash.find(i)->second -= 1;
            }
        }
        return ans;
    }
    int str1_str2(string s1, unordered_map<char, int> hash) {
        int ans = 0;
        for (auto i : s1) {
            if (hash.find(i) != hash.end() && hash.find(i)->second > 0) {
                ans++;
                hash.find(i)->second -= 1;
            }
        }
        return ans;
    }
    void _erase_target(string s, unordered_map<char, int> &hash) {
        for (auto i : s) {
            if (hash.find(i) != hash.end()) {
                if (hash.find(i)->second == 1)
                    hash.erase(hash.find(i));
                else
                    hash.find(i)->second -= 1;
            }
        }
        return;
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        unordered_map<char, unordered_set<string>> hash_s;
        unordered_map<char, unordered_set<string>>::iterator p_hash_s;
        unordered_set<string> temp;
        unordered_map<char, int> hash_t;
        for (int i = 0; i < stickers.size(); i++) {
            for (int ii = 0; ii < stickers[i].size(); ii++) {
                p_hash_s = hash_s.find(stickers[i][ii]);
                if (p_hash_s == hash_s.end()) {
                    temp.insert(stickers[i]);
                    hash_s.insert(make_pair(stickers[i][ii], temp));
                    temp.clear();
                }
                else {
                    if (p_hash_s->second.find(stickers[i]) == p_hash_s->second.end())
                        p_hash_s->second.insert(stickers[i]);
                }
            }
        }
        for (auto i : hash_s) {
            cout << i.first << " ";
            for (auto ii : i.second)
                cout << ii << "  ";
            cout << endl;
        }
        for (int i = 0; i < target.size(); i++) {
            if (hash_t.find(target[i]) == hash_t.end())
                hash_t.insert(make_pair(target[i], 1));
            else
                hash_t.find(target[i])->second += 1;
        }
        // 第一次遍历选取必选单词(字母是只有一个单词可以提供)
        string s_temp;
        int ans = 0;
        int ans_temp = 0;
        for (auto i : hash_t)
            cout << i.first << " " << i.second << endl;
        cout << endl;
        for (unordered_map<char, int>::iterator i = hash_t.begin(); i != hash_t.end(); i++) {
            if (i->second <= 0)
                continue;
            p_hash_s = hash_s.find(i->first);
            if (p_hash_s == hash_s.end())
                return -1; // target中的字母不在stickers单词中。
            else {
                if (p_hash_s->second.size() == 1) { // 此时target中的该字母只能由一个单词所提供
                    /*此时需要考虑
                    * target中如果该字符不是1个，但是一个单词只能提供一个，需要该单词多次被遍历
                    * target中的字符，只用被该单词提供一次，该单词只需要被一次遍历
                    */
                    s_temp = *p_hash_s->second.begin();
                    ans_temp = 0;
                    while (i->second > 0) {
                        ans_temp++;
                        for (auto ii : s_temp) {
                            if (hash_t.find(ii) != hash_t.end()) {
                                hash_t.find(ii)->second -= 1;
                            }
                        }
                    }
                    
                    ans += ans_temp;
                    cout << "ans = " << ans << endl;
                }
            }
        }
        _erase_hash_t(hash_t);
        if (hash_t.empty())
            return ans;
        target = "";
        for (auto i : hash_t) {
            for (int ii = 0; ii < i.second; ii++) {
                target.push_back(i.first);
            }
        } // 将target转换为剩余字母
        vector<int> stickers_max(stickers.size(), 0);
        int temp_max_i = 0;
        while (!hash_t.empty()) {
            for (int i = 0; i < stickers.size(); i++) {
                stickers_max[i] = str1_str2(stickers[i], hash_t);
            }
            temp_max_i = 0;
            for (int i = 1; i < stickers_max.size(); i++) {
                if (stickers_max[i] > stickers_max[temp_max_i])
                    temp_max_i = i;
            }
            _erase_target(stickers[temp_max_i], hash_t);
            ans++;
        }
        return ans;
    }
};
