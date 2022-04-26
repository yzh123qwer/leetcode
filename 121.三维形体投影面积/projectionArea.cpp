/*
883. 三维形体投影面积
在 n x n 的网格 grid 中，我们放置了一些与 x，y，z 三轴对齐的 1 x 1 x 1 立方体。

每个值 v = grid[i][j] 表示 v 个正方体叠放在单元格 (i, j) 上。

现在，我们查看这些立方体在 xy 、yz 和 zx 平面上的投影。

投影 就像影子，将 三维 形体映射到一个 二维 平面上。从顶部、前面和侧面看立方体时，我们会看到“影子”。

返回 所有三个投影的总面积 。

 

示例 1：



输入：[[1,2],[3,4]]
输出：17
解释：这里有该形体在三个轴对齐平面上的三个投影(“阴影部分”)。
示例 2:

输入：grid = [[2]]
输出：5
示例 3：

输入：[[1,0],[0,2]]
输出：8
*/
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int sum = 0;
        for (auto i : grid){
            for (auto ii : i){
                if (ii != 0)
                    sum += 1;
            }
        }
        int temp, n;
        n = grid.size();
        for (int i = 0; i < n; i++){
            temp = grid[i][0];
            for (int ii = 1; ii < n; ii++){
                if (temp < grid[i][ii])
                    temp = grid[i][ii];
            }
            sum += temp;
        }
        for (int i = 0; i < n; i++){
            temp = grid[0][i];
            for (int ii = 1; ii < n; ii++){
                if (temp < grid[ii][i])
                    temp = grid[ii][i];
            }
            sum += temp;
        }
        return sum;
    }
};
