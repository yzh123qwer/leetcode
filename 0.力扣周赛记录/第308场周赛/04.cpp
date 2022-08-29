/*
  2392. 给定条件下构造矩阵
给你一个 正 整数 k ，同时给你：

一个大小为 n 的二维整数数组 rowConditions ，其中 rowConditions[i] = [abovei, belowi] 和
一个大小为 m 的二维整数数组 colConditions ，其中 colConditions[i] = [lefti, righti] 。
两个数组里的整数都是 1 到 k 之间的数字。

你需要构造一个 k x k 的矩阵，1 到 k 每个数字需要 恰好出现一次 。剩余的数字都是 0 。

矩阵还需要满足以下条件：

对于所有 0 到 n - 1 之间的下标 i ，数字 abovei 所在的 行 必须在数字 belowi 所在行的上面。
对于所有 0 到 m - 1 之间的下标 i ，数字 lefti 所在的 列 必须在数字 righti 所在列的左边。
返回满足上述要求的 任意 矩阵。如果不存在答案，返回一个空的矩阵。

示例 1：

输入：k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
输出：[[3,0,0],[0,0,1],[0,2,0]]
解释：上图为一个符合所有条件的矩阵。
行要求如下：
- 数字 1 在第 1 行，数字 2 在第 2 行，1 在 2 的上面。
- 数字 3 在第 0 行，数字 2 在第 2 行，3 在 2 的上面。
列要求如下：
- 数字 2 在第 1 列，数字 1 在第 2 列，2 在 1 的左边。
- 数字 3 在第 0 列，数字 2 在第 1 列，3 在 2 的左边。
注意，可能有多种正确的答案。
示例 2：

输入：k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
输出：[]
解释：由前两个条件可以得到 3 在 1 的下面，但第三个条件是 3 在 1 的上面。
没有符合条件的矩阵存在，所以我们返回空矩阵。
*/
class Solution {
    vector<int> topo_sort(int k, vector<vector<int>>& edges) {
        vector<vector<int>> nums_1(k + 1); // 第0组不使用。
        vector<int> nums_i(k + 1, 0); // 第0组不使用。
        queue<int> Q;
        vector<int> ans;
        for (vector<int>& i : edges) {
            nums_1[i[0]].push_back(i[1]);
            nums_i[i[1]]++;
        }
        for (int i = 1; i < nums_i.size(); i++) {
            if (nums_i[i] == 0)
                Q.push(i);
        }
        while (!Q.empty()) {
            ans.push_back(Q.front());
            for (int i : nums_1[Q.front()]) {
                if (--nums_i[i] == 0)
                    Q.push(i);
            }
            Q.pop();
        }
        return ans;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row = topo_sort(k, rowConditions);
        vector<int> col = topo_sort(k, colConditions);
        if (row.size() < k || col.size() < k)
            return {};
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int ii = 0; ii < k; ii++) {
                if (row[i] == col[ii])
                    ans[i][ii] = row[i];
            }
        }
        return ans;
    }
};
