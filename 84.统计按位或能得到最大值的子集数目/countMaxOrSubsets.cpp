/*
2044. 统计按位或能得到最大值的子集数目
给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。

如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。如果选中的元素下标位置不一样，则认为两个子集 不同 。

对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。

 

示例 1：

输入：nums = [3,1]
输出：2
解释：子集按位或能得到的最大值是 3 。有 2 个子集按位或可以得到 3 ：
- [3]
- [3,1]
示例 2：

输入：nums = [2,2,2]
输出：7
解释：[2,2,2] 的所有非空子集的按位或都可以得到 2 。总共有 23 - 1 = 7 个子集。
示例 3：

输入：nums = [3,2,1,5]
输出：6
解释：子集按位或可能的最大值是 7 。有 6 个子集按位或可以得到 7 ：
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
*/
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<string> queue_;
        queue_ = int_str(nums.size());
        queue_.erase(queue_.begin()); // 第一个为000000...表示一个都不选
        vector<int> temp;
        int max, max_temp;
        max = max_temp = 0;
        int ans = 0;
        for (auto i : queue_){
            for (int j = 0; j < i.size(); j++){
                if (i[j] == '1')
                    temp.push_back(nums[j]);
            }
            if (temp.size() == 1){
                if (temp[0] > max){
                    max = temp[0];
                    ans = 1;
                }
                else if (temp[0] < max);
                else 
                    ans++;
                temp.clear();
            }
            else if (temp.size() == 2){
                max_temp = xORy(temp[0], temp[1]);
                if (max_temp > max){
                    max = max_temp;
                    ans = 1;
                }
                else if (max_temp < max);
                else 
                    ans++;
                temp.clear();
            }
            else {
                max_temp = xORy(temp[0], temp[1]);
                for (int ii = 2; ii < temp.size(); ii++)
                    max_temp = xORy(max_temp, temp[ii]);
                if (max_temp > max){
                    max = max_temp;
                    ans = 1;
                }
                else if (max_temp < max);
                else 
                    ans++;
                temp.clear();
            }
        }
        return ans;
    }
    int xORy(int x, int y = 0){
        if (y == 0)
            return x;
        int ans = 0;
        int i, j;
        for (i = 2, j = 1; x != 0 || y != 0; i = i << 1, j = j << 1){
            if (x == 0)
                return y + ans;
            if (y == 0)
                return x + ans;
            if (x % i != 0 || y % i != 0)
                ans += j;
            if (x % i != 0)
                x = x - j;
            if (y % i != 0)
                y = y - j;
        }
        return ans;
    }
    vector<string> int_str(int x){
        if (x != 1){
            vector<string> temp = int_str(x - 1);
            vector<string> ans;
            for (auto i : temp)
                ans.push_back(i + "0");
            for (auto i : temp)
                ans.push_back(i + "1");
            return ans;
        }
        else { // x = 1
            vector<string> ans;
            ans.push_back("0");
            ans.push_back("1");
            return ans;
        }
    }
};
