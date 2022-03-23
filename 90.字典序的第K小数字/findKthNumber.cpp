/*
440. 字典序的第K小数字
给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。

 

示例 1:

输入: n = 13, k = 2
输出: 10
解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
示例 2:

输入: n = 1, k = 1
输出: 1
*/
class Solution {
public:
    int findKthNumber(int n, int k) {
        int n_wide = 0;
        int n_2 = n;
        do {
            n_2 = n_2 / 10;
            n_wide += 1;
        }while(n_2 != 0);
        string x = "1";
        int ans = 1;
        int temp;
        while (ans != k){
            if (x.size() != n_wide){
                x.push_back('0');
                ans++;
            }
            else {
                if (x.back() != '9'){
                    temp = x.back() - '0';
                    temp++;
                    x.pop_back();
                    x += to_string(temp);
                    ans++;
                }
                else {
                    while (x.back() == '9')
                        x.pop_back();
                    temp = x.back() - '0';
                    temp++;
                    x.pop_back();
                    x += to_string(temp);
                    ans++;
                }
            }
            if (string_int(x) > n)
                ans--;
        }
        return string_int(x);
    }
    int string_int(string x){
        int ans = 0;
        while (x != ""){
            ans = ans * 10;
            if (x.front() == '0')
                ans += 0;
            else if (x.front() == '1')
                ans += 1;
            else if (x.front() == '2')
                ans += 2;
            else if (x.front() == '3')
                ans += 3;
            else if (x.front() == '4')
                ans += 4;
            else if (x.front() == '5')
                ans += 5;
            else if (x.front() == '6')
                ans += 6;
            else if (x.front() == '7')
                ans += 7;
            else if (x.front() == '8')
                ans += 8;
            else if (x.front() == '9')
                ans += 9;
            x.erase(x.begin());
        }
        return ans;
    }
};
