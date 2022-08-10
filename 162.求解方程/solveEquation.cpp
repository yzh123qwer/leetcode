/*
640. 求解方程
求解一个给定的方程，将x以字符串 "x=#value" 的形式返回。该方程仅包含 '+' ， '-' 操作，变量 x 和其对应系数。

如果方程没有解，请返回 "No solution" 。如果方程有无限解，则返回 “Infinite solutions” 。

如果方程中只有一个解，要保证返回值 'x' 是一个整数。

示例 1：

输入: equation = "x+5-3+x=6+x-2"
输出: "x=2"
示例 2:

输入: equation = "x=x"
输出: "Infinite solutions"
示例 3:

输入: equation = "2x=x"
输出: "x=0"
*/
class Solution {
public:
    string solveEquation(string equation) {
        int left_nums = 0;
        int right_nums = 0;
        int left_x = 0;
        int right_x = 0;
        int temp = 0;
        int i = 0;
        bool B = true;
        for (i = 0; equation[i] != '='; i++){
            if (equation[i] == 'x'){
                if (B == true)
                    left_x++;
                else 
                    left_x--;
            }
            else if (equation[i] == '-') 
                B = false;
            else if (equation[i] == '+')
                B = true;
            else { // equation[i]是数字
                temp = 0;
                temp = temp * 10 + equation[i] - '0';
                for (i++; equation[i] <= '9' && equation[i] >= '0'; i++)
                    temp = temp * 10 + equation[i] - '0';
                if (equation[i] == 'x'){
                    if (B == true)
                        left_x += temp;
                    else 
                        left_x -= temp;
                }
                else {
                    if (B == true)
                        left_nums += temp;
                    else 
                        left_nums -= temp;
                    i--;
                }
            }
        }
        B = true;
        for (i++; i < equation.size(); i++){
            if (equation[i] == 'x'){
                if (B == true)
                    right_x++;
                else 
                    right_x--;
            }
            else if (equation[i] == '-') 
                B = false;
            else if (equation[i] == '+')
                B = true;
            else { // equation[i]是数字
                temp = 0;
                temp = temp * 10 + equation[i] - '0';
                for (i++; equation[i] <= '9' && equation[i] >= '0'; i++)
                    temp = temp * 10 + equation[i] - '0';
                if (equation[i] == 'x'){
                    if (B == true)
                        right_x += temp;
                    else 
                        right_x -= temp;
                }
                else {
                    if (B == true)
                        right_nums += temp;
                    else 
                        right_nums -= temp;
                    i--;
                }
            }
        }
        left_x -= right_x;
        right_nums -= left_nums;
        if (left_x == 0) {
            if (right_nums == 0)
                return "Infinite solutions";
            else 
                return "No solution";
        }
        else {
            string ans = "x=";
            ans += to_string(right_nums / left_x);
            return ans;
        }
    }
};
