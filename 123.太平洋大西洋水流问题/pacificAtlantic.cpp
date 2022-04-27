/*
417. 太平洋大西洋水流问题
有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

返回 网格坐标 result 的 2D列表 ，其中 result[i] = [ri, ci] 表示雨水可以从单元格 (ri, ci) 流向 太平洋和大西洋 。

 

示例 1：



输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
示例 2：

输入: heights = [[2,1],[1,2]]
输出: [[0,0],[0,1],[1,0],[1,1]]
*/
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size(); // m是x坐标，n是y坐标。
        vector<vector<bool>> p_o(m, vector<bool>(n, false));
        queue<pair<int, int>> que;
        for (int i = 0; i < n; i++)
            que.push(make_pair(0, i));
        for (int i = 1; i < m; i++)
            que.push(make_pair(i, 0));
        int temp = que.size();
        pair<int, int> p_temp;
        while (!que.empty()) {
            for (temp = que.size(); temp > 0; temp--) {
                fun(que.front(), p_o, heights, que);
                que.pop();
            }
        }
        vector<vector<bool>> a_o(m, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            que.push(make_pair(m - 1, i));
        for (int i = 0; i < m - 1; i++)
            que.push(make_pair(i, n - 1));
        while (!que.empty()) {
            for (temp = que.size(); temp > 0; temp--) {
                fun(que.front(), a_o, heights, que);
                que.pop();
            }
        }
        vector<vector<int>> ans;
        vector<int> v_temp(2, 0);
        for (int i = 0; i < m; i++){
            for (int ii = 0; ii < n; ii++){
                if (a_o[i][ii] == true && p_o[i][ii] == true){
                    v_temp[0] = i;
                    v_temp[1] = ii;
                    ans.push_back(v_temp);
                }
            }
        }
        return ans;
    }
    void fun(const pair<int, int> _temp, vector<vector<bool>>& ocean, const vector<vector<int>>& heights, queue<pair<int, int>>& que) {
        if (ocean[_temp.first][_temp.second] == true)
            return;
        ocean[_temp.first][_temp.second] = true;
        int x = _temp.first, y = _temp.second;
        int m = heights.size(), n = heights[0].size();
        if (x != 0) {
            if (heights[x - 1][y] >= heights[x][y]) {
                que.push(make_pair(x - 1, y));
            }
        }
        if (y != n - 1) {
            if (heights[x][y + 1] >= heights[x][y])
                que.push(make_pair(x, y + 1));
        }
        if (x != m - 1) {
            if (heights[x + 1][y] >= heights[x][y])
                que.push(make_pair(x + 1, y));
        }
        if (y != 0) {
            if (heights[x][y - 1] >= heights[x][y])
                que.push(make_pair(x, y - 1));
        }
        return;
    }
};
