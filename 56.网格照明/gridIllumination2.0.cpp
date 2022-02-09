class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> x_line(n, 0);//x
        vector<int> y_line(n, 0);//y
        vector<int> xy_line(2 * n + 1, 0);//y - x + n
        vector<int> yx_line(2 * n + 1, 0);//x + y
        vector<vector<int>> light_lamps(n, vector<int>(n, 0));
        int x, y;
        for (auto i : lamps) {
            x = i[0];
            y = i[1];
            if (light_lamps[x][y] == 0) {
                light_lamps[x][y] = 1;
                x_line[x] += 1;
                y_line[y] += 1;
                xy_line[y - x + n] += 1;
                yx_line[x + y] += 1;
            }
        }
        vector<int> ans;
        int x1, y1;
        for (auto i : queries) {
            x = i[0];
            y = i[1];
            if (x_line[x] != 0)
                ans.push_back(1);
            else if (y_line[y] != 0)
                ans.push_back(1);
            else if (xy_line[y - x + n] != 0)
                ans.push_back(1);
            else if (yx_line[x + y] != 0)
                ans.push_back(1);
            else
                ans.push_back(0);
            if (light_lamps[x][y] == 1) {
                light_lamps[x][y] = 0;
                x_line[x] -= 1;
                y_line[y] -= 1;
                xy_line[y - x + n] -= 1;
                yx_line[x + y] -= 1;
            }
            if (x != 0) {
                x1 = x - 1;
                y1 = y;
                if (light_lamps[x1][y1] == 1) {
                    light_lamps[x1][y1] = 0;
                    x_line[x1] -= 1;
                    y_line[y1] -= 1;
                    xy_line[y1 - x1 + n] -= 1;
                    yx_line[x1 + y1] -= 1;
                }
            }
            if (x != 0 && y != 0) {
                x1 = x - 1;
                y1 = y - 1;
                if (light_lamps[x1][y1] == 1) {
                    light_lamps[x1][y1] = 0;
                    x_line[x1] -= 1;
                    y_line[y1] -= 1;
                    xy_line[y1 - x1 + n] -= 1;
                    yx_line[y1 + x1] -= 1;
                }
            }
            if (y != 0) {
                x1 = x;
                y1 = y - 1;
                if (light_lamps[x1][y1] == 1) {
                    light_lamps[x1][y1] = 0;
                    x_line[x1] -= 1;
                    y_line[y1] -= 1;
                    xy_line[y1 - x1 + n] -= 1;
                    yx_line[x1 + y1] -= 1;
                }
            }
            if (x != n - 1 && y != 0) {
                x1 = x + 1;
                y1 = y - 1;
                if (light_lamps[x1][y1] == 1) {
                    light_lamps[x1][y1] = 0;
                    x_line[x1] -= 1;
                    y_line[y1] -= 1;
                    xy_line[y1 - x1 + n] -= 1;
                    yx_line[x1 + y1] -= 1;
                }
            }
            if (x != n - 1) {
                x1 = x + 1;
                y1 = y;
                if (light_lamps[x1][y1] == 1) {
                    light_lamps[x1][y1] = 0;
                    x_line[x1] -= 1;
                    y_line[y1] -= 1;
                    xy_line[y1 - x1 + n] -= 1;
                    yx_line[x1 + y1] -= 1;
                }
            }
            if (x != n - 1 && y != n - 1) {
                x1 = x + 1;
                y1 = y + 1;
                if (light_lamps[x1][y1] == 1) {
                    light_lamps[x1][y1] = 0;
                    x_line[x1] -= 1;
                    y_line[y1] -= 1;
                    xy_line[y1 - x1 + n] -= 1;
                    yx_line[x1 + y1] -= 1;
                }
            }
            if (y != n - 1) {
                x1 = x;
                y1 = y + 1;
                if (light_lamps[x1][y1] == 1) {
                    light_lamps[x1][y1] = 0;
                    x_line[x1] -= 1;
                    y_line[y1] -= 1;
                    xy_line[y1 - x1 + n] -= 1;
                    yx_line[x1 + y1] -= 1;
                }
            }
            if (x != 0 && y != n - 1) {
                x1 = x - 1;
                y1 = y + 1;
                if (light_lamps[x1][y1] == 1) {
                    light_lamps[x1][y1] = 0;
                    x_line[x1] -= 1;
                    y_line[y1] -= 1;
                    xy_line[y1 - x1 + n] -= 1;
                    yx_line[x1 + y1] -= 1;
                }
            }
        }
        return ans;
    }
};
