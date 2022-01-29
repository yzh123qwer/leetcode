/*
1765. 地图中的最高点
给你一个大小为 m x n 的整数矩阵 isWater ，它代表了一个由 陆地 和 水域 单元格组成的地图。

如果 isWater[i][j] == 0 ，格子 (i, j) 是一个 陆地 格子。
如果 isWater[i][j] == 1 ，格子 (i, j) 是一个 水域 格子。
你需要按照如下规则给每个单元格安排高度：

每个格子的高度都必须是非负的。
如果一个格子是是 水域 ，那么它的高度必须为 0 。
任意相邻的格子高度差 至多 为 1 。当两个格子在正东、南、西、北方向上相互紧挨着，就称它们为相邻的格子。（也就是说它们有一条公共边）
找到一种安排高度的方案，使得矩阵中的最高高度值 最大 。

请你返回一个大小为 m x n 的整数矩阵 height ，其中 height[i][j] 是格子 (i, j) 的高度。如果有多种解法，请返回 任意一个 。
*/
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m, n;
        m = isWater.size();
        n = isWater[0].size();
        int i, j;
        vector<vector<int>> height(m, vector<int>(n, -1));
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    if (i != 0 && isWater[i - 1][j] == 0)
                        height[i - 1][j] = 1;
                    if (j != 0 && isWater[i][j - 1] == 0)
                        height[i][j - 1] = 1;
                    if (i != m - 1 && isWater[i + 1][j] == 0)
                        height[i + 1][j] = 1;
                    if (j != n - 1 && isWater[i][j + 1] == 0)
                        height[i][j + 1] = 1;
                }
            }
        bool S = false;
        int num = 2;
        while (S == false) {
            S = true;
            for (i = 0; i < m; i++) {
                for (j = 0; j < n; j++) {
                    if (height[i][j] == num - 1) {
                        if (i != 0 && height[i - 1][j] == -1)
                            height[i - 1][j] = num;
                        if (j != 0 && height[i][j - 1] == -1)
                            height[i][j - 1] = num;
                        if (i != m - 1 && height[i + 1][j] == -1)
                            height[i + 1][j] = num;
                        if (j != n - 1 && height[i][j + 1] == -1)
                            height[i][j + 1] = num;
                    }
                    else if (height[i][j] == -1) {
                        S = false;
                        continue;
                    }
                }
            }
            num++;  
        }
        return height;
    }
};
