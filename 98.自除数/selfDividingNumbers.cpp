/*
728. 自除数
自除数 是指可以被它包含的每一位数整除的数。

例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
自除数 不允许包含 0 。

给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。

 

示例 1：

输入：left = 1, right = 22
输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
示例 2:

输入：left = 47, right = 85
输出：[48,55,66,77]
*/
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        vector<int> temp;
        bool S;
        for (int i = left; i <= right; i++){
            nums_index(i, temp);
            if (temp[0] == -1)
                continue;
            else {
                S = true;
                for (int j = 0; j < temp.size(); j++){
                    if (i % temp[j] == 0)
                        continue;
                    else {
                        S = false;
                        break;
                    }
                }
                if (S == true)
                    ans.push_back(i);
            }
        }
        return ans;
    }
    void nums_index(int i, vector<int> &temp){
        temp.clear();
        while(i != 0){
            if (i % 10 == 0){
                temp.clear();
                temp.push_back(-1);
                break;
            }
            else {
                temp.push_back(i % 10);
                i = i / 10;
            }
        }
        return;
    }
};
