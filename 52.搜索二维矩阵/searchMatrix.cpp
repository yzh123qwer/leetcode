/*
74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

每行中的整数从左到右按升序排列。
每行的第一个整数大于前一行的最后一个整数。
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        if (matrix[0][0] > target)
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        if (matrix[m - 1][n - 1] < target)
            return false;
        int i = 1;
        int j = m * n;
        int mid;
        pair<int, int> mn;
        for (mid = (i + j) / 2; ; mid = (i + j) / 2){
            mn = turn(mid, m, n);
            if (matrix[mn.first][mn.second] > target){
                mn = turn(mid - 1, m, n);
                if (matrix[mn.first][mn.second] < target)
                    return false;
                else if (matrix[mn.first][mn.second] > target)
                    j = mid - 1;
                else 
                    return true;
                }
            else if (matrix[mn.first][mn.second] < target){
                mn = turn(mid + 1, m, n);
                if (matrix[mn.first][mn.second] > target)
                    return false;
                else if (matrix[mn.first][mn.second] < target)
                    i = mid + 1;
                else
                    return true;
            }
            else 
                return true;
        }
    }
private:
    pair<int, int> turn(int x, int m, int n){
        pair<int, int> mn;
        if (x <= n){
            mn.first = 0;
            mn.second = x - 1;
            return mn;
        }
        mn.second = x % n - 1;
        if (mn.second == -1){
            mn.second = n - 1;
            mn.first = x / n - 1;
        }
        else
            mn.first = x / n;
        return mn;
    }
};
