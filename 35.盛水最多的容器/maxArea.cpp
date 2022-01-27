/*
11. 盛最多水的容器
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i, j;
        int max_return = 0;
        int tmp;
        for (i = 0, j = height.size() - 1; i < j; ){
            if (height[i] >= height[j]){
                tmp = height[j] * (j - i);
                j--;
            }
            else{
                tmp = height[i] * (j - i);
                i++;
            }
            if (tmp > max_return)
                max_return = tmp;
        }
        return max_return;
    }
};
