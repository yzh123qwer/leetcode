/*
764. 最大加号标志
在一个 n x n 的矩阵 grid 中，除了在数组 mines 中给出的元素为 0，其他每个元素都为 1。mines[i] = [xi, yi]表示 grid[xi][yi] == 0

返回  grid 中包含 1 的最大的 轴对齐 加号标志的阶数 。如果未找到加号标志，则返回 0 。

一个 k 阶由 1 组成的 “轴对称”加号标志 具有中心网格 grid[r][c] == 1 ，以及4个从中心向上、向下、向左、向右延伸，长度为 k-1，由 1 组成的臂。注意，只有加号标志的所有网格要求为 1 ，别的网格可能为 0 也可能为 1 。

 

示例 1：



输入: n = 5, mines = [[4, 2]]
输出: 2
解释: 在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
示例 2：



输入: n = 1, mines = [[0, 0]]
输出: 0
解释: 没有加号标志，返回 0 。
*/
class Solution {
public:
	int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
		vector<vector<vector<int>>> ans(n, vector<vector<int>>(n, vector<int>(4, 1)));
		for (vector<int>& i : mines) {
			ans[i[0]][i[1]][0] = ans[i[0]][i[1]][1] = ans[i[0]][i[1]][2] = ans[i[0]][i[1]][3] = 0;
		}
		for (int i = 1; i < n; i++) {
			for (int ii = 0; ii < n; ii++) {
				if (ans[i][ii][0] != 0)
					ans[i][ii][0] = ans[i - 1][ii][0] + 1;
				if (ans[ii][i][2] != 0)
					ans[ii][i][2] = ans[ii][i - 1][2] + 1;
			}
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int ii = 0; ii < n; ii++) {
				if (ans[i][ii][1] != 0)
					ans[i][ii][1] = ans[i + 1][ii][1] + 1;
				if (ans[ii][i][3] != 0)
					ans[ii][i][3] = ans[ii][i + 1][3] + 1;
			}
		}
		int ret = 0;
		int min_temp = 0;
		for (int i = 0; i < n; i++) {
			for (int ii = 0; ii < n; ii++) {
				min_temp = min(min(ans[i][ii][0], ans[i][ii][1]), min(ans[i][ii][2], ans[i][ii][3]));
				if (min_temp > ret)
					ret = min_temp;
			}
		}
		return ret;

	}
};
