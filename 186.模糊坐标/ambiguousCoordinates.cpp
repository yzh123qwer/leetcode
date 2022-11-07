/*
816. 模糊坐标
我们有一些二维坐标，如 "(1, 3)" 或 "(2, 0.5)"，然后我们移除所有逗号，小数点和空格，得到一个字符串S。返回所有可能的原始字符串到一个列表中。

原始的坐标表示法不会存在多余的零，所以不会出现类似于"00", "0.0", "0.00", "1.0", "001", "00.01"或一些其他更小的数来表示坐标。此外，一个小数点前至少存在一个数，所以也不会出现“.1”形式的数字。

最后返回的列表可以是任意顺序的。而且注意返回的两个数字中间（逗号之后）都有一个空格。

 

示例 1:
输入: "(123)"
输出: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
示例 2:
输入: "(00011)"
输出:  ["(0.001, 1)", "(0, 0.011)"]
解释: 
0.0, 00, 0001 或 00.01 是不被允许的。
示例 3:
输入: "(0123)"
输出: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
示例 4:
输入: "(100)"
输出: [(10, 0)]
解释: 
1.0 是不被允许的。
*/
class Solution {
    vector<string> ans;
    bool fun_1(string x, string y){  // 判断传入字符串x和y是否为合法数字取出小数点得到的
        if (fun_1(x) == false)
            return false;
        if (fun_1(y) == false)
            return false;
        return true;
    }
    bool fun_1(string x){ // 判断传入字符串x是否为合法数字取出小数点得到的
        if (x.size() == 1)
            return true;
        if (x[0] == '0'){
            if (x[x.size() - 1] == '0')
                return false;
            else 
                return true;
        }
        else 
            return true;
    }
    void fun_2(string x, string y){
        vector<string> x_ori;
        vector<string> y_ori;
        string temp;
        fun_3(x, x_ori);
        fun_3(y, y_ori);
        for (int i = 0; i < x_ori.size(); i++){
            for (int ii = 0; ii < y_ori.size(); ii++){
                temp = "(" + x_ori[i] + ", " + y_ori[ii] + ")";
                ans.push_back(temp);
            }
        }
        return;
    }
    void fun_3(string x, vector<string> &x_ori){
        string temp;
        if (x == "0"){
            x_ori.push_back(x);
            return;
        }
        if (x[0] == '0'){
            temp = "0.";
            for (int i = 1; i < x.size(); i++)
                temp.push_back(x[i]);
            x_ori.push_back(temp);
            return;
        }
        x_ori.push_back(x);
        if (x.back() == '0')
            return;
        for (int i = 0; i < x.size() - 1; i++){
            temp.clear();
            for (int ii = 0; ii <= i; ii++)
                temp.push_back(x[ii]);
            temp.push_back('.');
            for (int ii = i + 1; ii < x.size(); ii++)
                temp.push_back(x[ii]);
            x_ori.push_back(temp);
        }
        return;
    }
public:
    vector<string> ambiguousCoordinates(string s) {
        string x;
        string y;
        for (int i = 1; i < s.size() - 2; i++){
            x.clear();
            for (int ii = 1; ii <= i; ii++)
                x.push_back(s[ii]);
            y.clear();
            for (int ii = i + 1; ii < s.size() - 1; ii++)
                y.push_back(s[ii]);
            if (fun_1(x, y) == false)
                continue;
            fun_2(x, y);
        }
        return ans;
    }
};
