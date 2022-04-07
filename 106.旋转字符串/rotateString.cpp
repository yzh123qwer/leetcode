/*
796. 旋转字符串
给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。

s 的 旋转操作 就是将 s 最左边的字符移动到最右边。 

例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
 

示例 1:

输入: s = "abcde", goal = "cdeab"
输出: true
示例 2:

输入: s = "abcde", goal = "abced"
输出: false
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())
            return false;
        char goal_f = goal[0];
        vector<int> s_i;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == goal_f)
                s_i.push_back(i);
        }
        if (s_i.size() == 0)
            return false;
        bool S = true;
        for (auto i : s_i){
            S = true;
            for (int n = i, m = 0; m < goal.size(); m++){
                if (goal[m] != s[n]){
                    S = false;
                    break;
                }
                if (n == s.size() - 1)
                    n = 0;
                else 
                    n++;
            }
            if (S == true)
                return true;
        }
        return false;
    }
};
