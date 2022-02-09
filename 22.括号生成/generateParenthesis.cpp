/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        int left_nums, right_nums;
        left_nums = right_nums = 0;
        vector<string> ans;
        push_parenthess(n, temp, left_nums, right_nums, ans);
        return ans;
    }
private:
    void push_parenthess(int n, string& temp, int& left_nums, int& right_nums, vector<string>& ans){
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }
        else {
            if (left_nums < n) {
                temp.push_back('(');
                left_nums += 1;
                push_parenthess(n, temp, left_nums, right_nums, ans);
                temp.pop_back();
                left_nums -= 1;
            }
            if (right_nums < left_nums) {
                temp.push_back(')');
                right_nums += 1;
                push_parenthess(n, temp, left_nums, right_nums, ans);
                temp.pop_back();
                right_nums -= 1;
            }
            return;
        }
    }
};
