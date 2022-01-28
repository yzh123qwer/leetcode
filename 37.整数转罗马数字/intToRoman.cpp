/*
12. 整数转罗马数字
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。

 

示例 1:

输入: num = 3
输出: "III"
示例 2:

输入: num = 4
输出: "IV"
示例 3:

输入: num = 9
输出: "IX"
示例 4:

输入: num = 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: num = 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/class Solution {
public:
    string intToRoman(int num) {
        string s;
        int i;
        if (num / 1000 != 0)
            for (i = 0; i < num / 1000; i++)
                s.push_back('M');
        num = num % 1000;
        if (num > 500){
            if (num > 900){
                s.push_back('C');
                s.push_back('M');
            }
            else if (num == 900){
                s.push_back('C');
                s.push_back('M');
                return s;
            }
            else{//500-899
                s.push_back('D');
                for (i = 0; i < (num - 500) / 100; i++)
                    s.push_back('C');
            }
        }
        else if (num < 500){
            if (num > 400){
                s.push_back('C');
                s.push_back('D');
            }
            else if (num == 400){
                s.push_back('C');
                s.push_back('D');
                return s;
            }
            else{
                for (i = 0; i < num / 100; i++)
                    s.push_back('C');
            }
        }
        else{//num == 500
            s.push_back('D');
            return s;
        }
        num = num % 100;
        if (num > 50){
            if (num > 90){
                s.push_back('X');
                s.push_back('C');
            }
            else if (num == 90){
                s.push_back('X');
                s.push_back('C');
                return s;
            }
            else {
                s.push_back('L');
                for (i = 0; i < (num - 50) / 10; i++)
                    s.push_back('X');
            }
        }
        else if (num < 50){
            if (num > 40){
                s.push_back('X');
                s.push_back('L');
            }
            else if (num == 40){
                s.push_back('X');
                s.push_back('L');
                return s;
            }
            else {
                for (i = 0; i < num / 10; i++)
                    s.push_back('X');
            }
        }
        else{//num == 50
            s.push_back('L');
            return s;
        }
        num = num % 10;
        if (num > 5){
            if (num == 9){
                s.push_back('I');
                s.push_back('X');
                return s;
            }
            else{
                s.push_back('V');
                for (i = 0; i < num - 5; i++)
                    s.push_back('I');
                return s;
            }
        }
        else if (num < 5){
            if (num == 4){
                s.push_back('I');
                s.push_back('V');
                return s;
            }
            else {
                for (i = 0; i < num; i++)
                    s.push_back('I');
                return s;
            }
        }
        else {
            s.push_back('V');
            return s;
        }
    }
};
