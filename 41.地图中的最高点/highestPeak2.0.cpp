class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m, n;
        m = isWater.size();
        n = isWater[0].size();
        int i, j;
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    height[i][j] = 0;
                    if (i != 0 && isWater[i - 1][j] == 0) {
                        height[i - 1][j] = 1;
                        q.emplace(i - 1, j);
                    }
                    if (j != 0 && isWater[i][j - 1] == 0) {
                        height[i][j - 1] = 1;
                        q.emplace(i, j - 1);
                    }
                    if (i != m - 1 && isWater[i + 1][j] == 0) {
                        height[i + 1][j] = 1;
                        q.emplace(i + 1, j);
                    }
                    if (j != n - 1 && isWater[i][j + 1] == 0) {
                        height[i][j + 1] = 1;
                        q.emplace(i, j + 1);
                    }
                }
            }
        int num = 2;
        pair<int, int> end;
        pair<int, int> begin;
        while (!q.empty()) {//队列中不是空的
            begin = q.front();
            if (height[begin.first][begin.second] == num - 1) {
                q.pop();
                if (begin.first != 0 && height[begin.first - 1][begin.second] == -1) {
                    height[begin.first - 1][begin.second] = num;
                    q.emplace(begin.first - 1, begin.second);
                }
                if (begin.second != 0 && height[begin.first][begin.second - 1] == -1) {
                    height[begin.first][begin.second - 1] = num;
                    q.emplace(begin.first, begin.second - 1);
                }
                if (begin.first != m - 1 && height[begin.first + 1][begin.second] == -1) {
                    height[begin.first + 1][begin.second] = num;
                    q.emplace(begin.first + 1, begin.second);
                }
                if (begin.second != n - 1 && height[begin.first][begin.second + 1] == -1) {
                    height[begin.first][begin.second + 1] = num;
                    q.emplace(begin.first, begin.second + 1);
                }
            }
            else
                num++;
        }
        return height;
    }
};
