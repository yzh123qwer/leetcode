/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

 

示例 1：



输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9
*/
class Solution {
    int height_i(int i, const vector<int> &left_max, const vector<int> &right_max, const vector<int> &height){
        if (height[i] >= left_max[i] || height[i] >= right_max[i])
            return 0;
        // else height[i] < left_max[i] && height[i] < right_max[i]
        int ans = left_max[i] - height[i];
        if (right_max[i] - height[i] < ans)
            return right_max[i] - height[i];
        else 
            return ans;
    }
public:
    int trap(vector<int>& height) {
        vector<int> left_max;
        vector<int> right_max(height.size(), 0);
        int max_temp = height[0];
        left_max.push_back(0);
        for (int i = 1; i < height.size(); i++){
            left_max.push_back(max_temp);
            if (height[i] > max_temp)
                max_temp = height[i];
        }
        max_temp = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            right_max[i] = max_temp;
            if (height[i] > max_temp)
                max_temp = height[i];
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++){
            ans += height_i(i, left_max, right_max, height);
        }
        return ans;
    }
};
