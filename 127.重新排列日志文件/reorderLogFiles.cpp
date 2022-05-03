/*
937. 重新排列日志文件
给你一个日志数组 logs。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的 标识符 。

有两种不同类型的日志：

字母日志：除标识符之外，所有字均由小写字母组成
数字日志：除标识符之外，所有字均由数字组成
请按下述规则将日志重新排序：

所有 字母日志 都排在 数字日志 之前。
字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
数字日志 应该保留原来的相对顺序。
返回日志的最终顺序。

 

示例 1：

输入：logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
输出：["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
解释：
字母日志的内容都不同，所以顺序为 "art can", "art zero", "own kit dig" 。
数字日志保留原来的相对顺序 "dig1 8 1 5 1", "dig2 3 6" 。
示例 2：

输入：logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
*/
class Solution {
    static bool fun(string s1, string s2) {
        int i, j;
        for (i = 0; i < s1.size(); i++) {
            if (s1[i] == ' ')
                break;
        }
        while (s1[i] == ' ')
            i++;
        for (j = 0; j < s2.size(); j++) {
            if (s2[j] == ' ')
                break;
        }
        while (s2[j] == ' ')
            j++;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] < s2[j])
                return true;
            else if (s1[i] > s2[j])
                return false;
            else {
                i++; j++;
                continue;
            }
        }
        if (i == s1.size() && j == s2.size()) {
            int ii = 0;
            while (s1[ii] != ' ' && s2[ii] != ' ') {
                if (s1[ii] < s2[ii])
                    return true;
                else if (s1[ii] > s2[ii])
                    return false;
                else
                    ii++;
            }
            if (s1[ii] == ' ')
                return true;
            else
                return false;
        }
        if (i == s1.size())
            return true;
        else
            return false;
    }
    bool log_nums(string s1) {
        int i;
        for (i = 0; i < s1.size(); i++) {
            if (s1[i] == ' ')
                break;
        }
        while (s1[i] == ' ')
            i++;
        if (s1[i] <= '9' && s1[i] >= '0')
            return true;
        else
            return false;
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> nums_temp;
        vector<string> s_temp;
        for (string i : logs) {
            if (log_nums(i) == true) 
                nums_temp.push_back(i);
            else
                s_temp.push_back(i);
        }
        sort(s_temp.begin(), s_temp.end(), fun);
        vector<string> ans;
        for (string i : s_temp)
            ans.push_back(i);
        for (string i : nums_temp)
            ans.push_back(i);
        return ans;
    }
};
