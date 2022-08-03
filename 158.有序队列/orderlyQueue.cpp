/*
899. 有序队列
给定一个字符串 s 和一个整数 k 。你可以从 s 的前 k 个字母中选择一个，并把它加到字符串的末尾。

返回 在应用上述步骤的任意数量的移动后，字典上最小的字符串 。

 

示例 1：

输入：s = "cba", k = 1
输出："acb"
解释：
在第一步中，我们将第一个字符（“c”）移动到最后，获得字符串 “bac”。
在第二步中，我们将第一个字符（“b”）移动到最后，获得最终结果 “acb”。
示例 2：

输入：s = "baaca", k = 3
输出："aaabc"
解释：
在第一步中，我们将第一个字符（“b”）移动到最后，获得字符串 “aacab”。
在第二步中，我们将第三个字符（“c”）移动到最后，获得最终结果 “aaabc”。
*/
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k == 1) {
            string smallest = s;
            int n = s.size();
            for (int i = 1; i < n; i++) {
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                if (s < smallest) {
                    smallest = s;
                }
            }
            return smallest;
        }
        else {
            vector<int> abc(26, 0); // 桶排序
            for (int i = 0; i < s.size(); i++)
                abc[s[i] - 'a']++;
            string ans;
            for (int i = 0; i < 26; i++){
                for (int ii = 0; ii < abc[i]; ii++)
                    ans.push_back('a' + i);
            }
            return ans;
        }
    }
};
