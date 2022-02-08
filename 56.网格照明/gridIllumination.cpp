/*
1001. 网格照明
在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。

给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli] 的灯。即便同一盏灯可能在 lamps 中多次列出，不会影响这盏灯处于 打开 状态。

当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 所有其他单元格 。

另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，如果单元格 [rowj, colj] 是被照亮的，则查询结果为 1 ，否则为 0 。在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj] 上及相邻 8 个方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。

返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，1 表示照亮，0 表示未照亮。

 

示例 1：


输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
输出：[1,0]
解释：最初所有灯都是关闭的。在执行查询之前，打开位于 [0, 0] 和 [4, 4] 的灯。第 0 次查询检查 grid[1][1] 是否被照亮（蓝色方框）。该单元格被照亮，所以 ans[0] = 1 。然后，关闭红色方框中的所有灯。

第 1 次查询检查 grid[1][0] 是否被照亮（蓝色方框）。该单元格没有被照亮，所以 ans[1] = 0 。然后，关闭红色矩形中的所有灯。

示例 2：

输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
输出：[1,1]
示例 3：

输入：n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
输出：[1,1,0]
*/
class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<vector<int>> the_lamps(n, vector<int>(n, 0));
        //0表示未被照亮，-1表示打开，1至n表示被n个灯照亮
        for (auto i : lamps) {
            if (the_lamps[i[0]][i[1]] == -1)
                continue;
            the_lamps[i[0]][i[1]] = -1;
            light_others(i, the_lamps);
        }
        vector<int> vec_return(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            if (the_lamps[queries[i][0]][queries[i][1]] == 0)
                vec_return[i] = 0;
            else //是打开或已经照亮
                vec_return[i] = 1;
            close(queries[i], the_lamps);
        }
        return vec_return;
    }
private:
    void light_others(vector<int> a, vector<vector<int>>& the_lamps) {
        int n = the_lamps.size();
        int x = a[0];
        int y = a[1];
        int i, j;
        for (i = x + 1; i < n; i++)
            if (the_lamps[i][y] != -1)
                the_lamps[i][y] += 1;
        for (i = x - 1; i > -1; i--)
            if (the_lamps[i][y] != -1)
                the_lamps[i][y] += 1;
        for (j = y + 1; j < n; j++)
            if (the_lamps[x][j] != -1)
                the_lamps[x][j] += 1;
        for (j = y - 1; j > -1; j--)
            if (the_lamps[x][j] != -1)
                the_lamps[x][j] += 1;
        for (i = x + 1, j = y + 1; i < n && j < n; i++, j++)
            if (the_lamps[i][j] != -1)
                the_lamps[i][j] += 1;
        for (i = x - 1, j = y + 1; i > -1 && j < n; i--, j++)
            if (the_lamps[i][j] != -1)
                the_lamps[i][j] += 1;
        for (i = x + 1, j = y - 1; i < n && j > -1; i++, j--)
            if (the_lamps[i][j] != -1)
                the_lamps[i][j] += 1;
        for (i = x - 1, j = y - 1; i > -1 && j > -1; i--, j--)
            if (the_lamps[i][j] != -1)
                the_lamps[i][j] += 1;
        return;
    }
    void close_others(int x, int y, vector<vector<int>>& the_lamps) {
        int n = the_lamps.size();
        int i, j;
        for (i = x + 1; i < n; i++) {
            if (the_lamps[i][y] == -1)//如果在关闭过程中遇到其他灯，则自身应该被照亮1次
                the_lamps[x][y] += 1;
            else if (the_lamps[i][y] != 0)
                the_lamps[i][y] -= 1;
        }
        for (i = x - 1; i > -1; i--) {
            if (the_lamps[i][y] == -1)
                the_lamps[x][y] += 1;
            else if (the_lamps[i][y] != 0)
                the_lamps[i][y] -= 1;
        }
        for (j = y + 1; j < n; j++) {
            if (the_lamps[x][j] == -1)
                the_lamps[x][y] += 1;
            else if (the_lamps[x][j] != 0)
                the_lamps[x][j] -= 1;
        }
        for (j = y - 1; j > -1; j--) {
            if (the_lamps[x][j] == -1)
                the_lamps[x][y] += 1;
            else if (the_lamps[x][j] != 0)
                the_lamps[x][j] -= 1;
        }
        for (i = x + 1, j = y + 1; i < n && j < n; i++, j++) {
            if (the_lamps[i][j] == -1)
                the_lamps[x][y] += 1;
            else if (the_lamps[i][j] != 0)
                the_lamps[i][j] -= 1;
        }
        for (i = x - 1, j = y + 1; i > -1 && j < n; i--, j++) {
            if (the_lamps[i][j] == -1)
                the_lamps[x][y] += 1;
            else if (the_lamps[i][j] != 0)
                the_lamps[i][j] -= 1;
        }
        for (i = x + 1, j = y - 1; i < n && j > -1; i++, j--) {
            if (the_lamps[i][j] == -1)
                the_lamps[x][y] += 1;
            else if (the_lamps[i][j] != 0)
                the_lamps[i][j] -= 1;
        }
        for (i = x - 1, j = y - 1; i > -1 && j > -1; i--, j--) {
            if (the_lamps[i][j] == -1)
                the_lamps[x][y] += 1;
            else if (the_lamps[i][j] != 0)
                the_lamps[i][j] -= 1;
        }
        return;
    }
    void close(vector<int> a, vector<vector<int>>& the_lamps) {
        int n = the_lamps.size();
        int x = a[0];
        int y = a[1];
        if (the_lamps[x][y] == -1) {
            the_lamps[x][y] = 0;
            close_others(x, y, the_lamps);
        }
        if (x != 0) {
            if (the_lamps[x - 1][y] == -1) {
                the_lamps[x - 1][y] = 0;
                close_others(x - 1, y, the_lamps);
            }
        }
        if (x != 0 && y != 0) {
            if (the_lamps[x - 1][y - 1] == -1) {
                the_lamps[x - 1][y - 1] = 0;
                close_others(x - 1, y - 1, the_lamps);
            }
        }
        if (y != 0) {
            if (the_lamps[x][y - 1] == -1) {
                the_lamps[x][y - 1] = 0;
                close_others(x, y - 1, the_lamps);
            }
        }
        if (x != n - 1 && y != 0) {
            if (the_lamps[x + 1][y - 1] == -1) {
                the_lamps[x + 1][y - 1] = 0;
                close_others(x + 1, y - 1, the_lamps);
            }
        }
        if (x != n - 1) {
            if (the_lamps[x + 1][y] == -1) {
                the_lamps[x + 1][y] = 0;
                close_others(x + 1, y, the_lamps);
            }
        }
        if (x != n - 1 && y != n - 1) {
            if (the_lamps[x + 1][y + 1] == -1) {
                the_lamps[x + 1][y + 1] = 0;
                close_others(x + 1, y + 1, the_lamps);
            }
        }
        if (y != n - 1) {
            if (the_lamps[x][y + 1] == -1) {
                the_lamps[x][y + 1] = 0;
                close_others(x, y + 1, the_lamps);
            }
        }if (x != 0 && y != n - 1) {
            if (the_lamps[x - 1][y + 1] == -1) {
                the_lamps[x - 1][y + 1] = 0;
                close_others(x - 1, y + 1, the_lamps);
            }
        }
    }
};
