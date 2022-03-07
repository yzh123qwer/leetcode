/*
504. 七进制数
给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。

 

示例 1:

输入: num = 100
输出: "202"
示例 2:

输入: num = -7
输出: "-10"
*/
class Solution {
public:
    string convertToBase7(int num) {
        bool S;
        int i, j, temp;
        string ans;
        if (num > 0)
            S = true;
        else if (num < 0){
            num = -num;
            S = false;
        }
        else { //num == 0
            ans.push_back('0');
            return ans;
        }
        for (i = 1, j = 7; j <= num; i++, j = j * 7);
        for (j = j / 7; j != 0; j = j / 7){
            temp = num / j;
            if (temp == 0)
                ans.push_back('0');
            else if (temp == 1)
                ans.push_back('1');
            else if (temp == 2)
                ans.push_back('2');
            else if (temp == 3)
                ans.push_back('3');
            else if (temp == 4)
                ans.push_back('4');
            else if (temp == 5)
                ans.push_back('5');
            else if (temp == 6)
                ans.push_back('6');
            num = num - temp * j;
        }
        if (S == true)
            return ans;
        else 
            ans.insert(0, "-");
        return ans;
    }
};
