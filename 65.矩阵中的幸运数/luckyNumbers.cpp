/*
1380. 矩阵中的幸运数
给你一个 m * n 的矩阵，矩阵中的数字 各不相同 。请你按 任意 顺序返回矩阵中的所有幸运数。

幸运数是指矩阵中满足同时下列两个条件的元素：

在同一行的所有元素中最小
在同一列的所有元素中最大
 

示例 1：

输入：matrix = [[3,7,8],[9,11,13],[15,16,17]]
输出：[15]
解释：15 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 2：

输入：matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
输出：[12]
解释：12 是唯一的幸运数，因为它是其所在行中的最小值，也是所在列中的最大值。
示例 3：

输入：matrix = [[7,8],[1,2]]
输出：[7]
*/
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i, j;
        vector<int> ans;
        vector<int> min_vec(m, 0);
        int min;
        for (i = 0, min = matrix[0][0]; i < m; i++){
            min = matrix[i][0];
            for (j = 1; j < n; j++)
                if (matrix[i][j] < min){
                    min = matrix[i][j];
                    min_vec[i] = j;
                }
        }
        bool S;
        int max;
        for (i = 0; i < m; i++){
            max = matrix[i][min_vec[i]];
            S = true;
            for (j = 0; j < m; j++){
                if (matrix[j][min_vec[i]] > max){
                    S = false;
                    break;
                }
            }
            if (S == true)
                ans.push_back(max);
            else 
                continue;
        }
        return ans;
    }
};
