/*
17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



 

示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> num_chars = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> s;
        vector<int> digits_vec;
        for (char i : digits){
            if (i == '2')
                digits_vec.push_back(2);
            else if (i == '3')
                digits_vec.push_back(3);
            else if (i == '4')
                digits_vec.push_back(4);
            else if (i == '5')
                digits_vec.push_back(5);
            else if (i == '6')
                digits_vec.push_back(6);
            else if (i == '7')
                digits_vec.push_back(7);
            else if (i == '8')
                digits_vec.push_back(8);
            else //i == '9'
                digits_vec.push_back(9);
        }
        if (n == 0)
            return s;
        else if (n == 1){
            string tmp = "#";
            for (char i : num_chars[digits_vec[0]]){
                tmp[0] = i;
                s.push_back(tmp);
            }
        }
        else if (n == 2){
            string tmp = "##";
            for (char i : num_chars[digits_vec[0]]){
                tmp[0] = i;
                for (char j : num_chars[digits_vec[1]]){
                    tmp [1] = j;
                    s.push_back(tmp);
                }
            }
        }
        else if (n == 3){
            string tmp = "###";
            for (char i : num_chars[digits_vec[0]]){
                tmp[0] = i;
                for (char j : num_chars[digits_vec[1]]){
                    tmp[1] = j;
                    for (char k : num_chars[digits_vec[2]]){
                        tmp[2] = k;
                        s.push_back(tmp);
                    }
                }
            }
        }
        else if (n == 4){
            string tmp = "####";
            for (char i : num_chars[digits_vec[0]]){
                tmp[0] = i;
                for (char j : num_chars[digits_vec[1]]){
                    tmp[1] = j;
                    for (char k : num_chars[digits_vec[2]]){
                        tmp[2] = k;
                        for (char l : num_chars[digits_vec[3]]){
                            tmp[3] = l;
                            s.push_back(tmp);
                        }
                    }
                }
            }
        }
        return s;
    }
};
