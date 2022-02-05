/*
1219. 黄金矿工
你要开发一座金矿，地质勘测学家已经探明了这座金矿中的资源分布，并用大小为 m * n 的网格 grid 进行了标注。每个单元格中的整数就表示这一单元格中的黄金数量；如果该单元格是空的，那么就是 0。

为了使收益最大化，矿工需要按以下规则来开采黄金：

每当矿工进入一个单元，就会收集该单元格中的所有黄金。
矿工每次可以从当前位置向上下左右四个方向走。
每个单元格只能被开采（进入）一次。
不得开采（进入）黄金数目为 0 的单元格。
矿工可以从网格中 任意一个 有黄金的单元格出发或者是停止。
 

示例 1：

输入：grid = [[0,6,0],[5,8,7],[0,9,0]]
输出：24
解释：
[[0,6,0],
 [5,8,7],
 [0,9,0]]
一种收集最多黄金的路线是：9 -> 8 -> 7。
示例 2：

输入：grid = [[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]
输出：28
解释：
[[1,0,7],
 [2,0,6],
 [3,4,5],
 [0,3,0],
 [9,0,20]]
一种收集最多黄金的路线是：1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7。
*/
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int x, y;
        int m = grid.size();
        int n = grid[0].size();
        int* gold = (int*)malloc(sizeof(int));
        *gold = 0;
        int* ans = (int*)malloc(sizeof(int));
        *ans = 0;
        for (x = 0; x < m; x++) {
            for (y = 0; y < n; y++) {
                if (grid[x][y] == 0)
                    continue;
                mine(x, y, grid, gold, ans);
            }
        }
        return *ans;
    }
private:
    void mine(int x, int y, vector<vector<int>>& grid, int* gold, int* ans) {
        int tmp_grid = grid[x][y];
        int tmp_gold = *gold;
        *gold = *gold + grid[x][y];
        grid[x][y] = 0;
        if (x != 0 && grid[x - 1][y] != 0) {
            mine(x - 1, y, grid, gold, ans);
        }
        if (x != grid.size() - 1 && grid[x + 1][y] != 0) {
            mine(x + 1, y, grid, gold, ans);
        }
        if (y != 0 && grid[x][y - 1] != 0) {
            mine(x, y - 1, grid, gold, ans);
        }
        if (y != grid[0].size() - 1 && grid[x][y + 1] != 0) {
            mine(x, y + 1, grid, gold, ans);
        }
        grid[x][y] = tmp_grid;
        if (*gold > *ans)
            *ans = *gold;
        *gold = tmp_gold;
        return;
    }
};
