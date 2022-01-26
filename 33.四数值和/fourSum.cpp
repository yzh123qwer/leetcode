/*
18. 四数之和
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

 

示例 1：

输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：

输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        InsertSort(nums);
        int n = nums.size();
        vector<vector<int>> vec_return;
        vector<vector<int>> vec_three;
        vector<int> vec_tmp(4);
        int tmp;
        int i;
        for (i = 0; i < n; i++){
            if (i != 0 && tmp == *nums.rbegin()){
                nums.pop_back();
                continue;
            }
            tmp = *nums.rbegin();
            nums.pop_back();
            vec_three = threeSum(nums, target - tmp);
            for (vector<int> a : vec_three){
                vec_tmp[0] = a[0];
                vec_tmp[1] = a[1];
                vec_tmp[2] = a[2];
                vec_tmp[3] = tmp;
                vec_return.push_back(vec_tmp);
            }
        }
        return vec_return;
    }
private:
    vector<vector<int>> threeSum(vector<int>& nums, int tatget){//输入数组要求已经从小到大排序
        int i, j, k;
        vector<vector<int>> vec_return;
        vector<int> tmp(3);
        int n = nums.size();
        for (i = 0; i < n; i++){
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            k = n - 1;
            for (j = i + 1; j < k && j < n; j++){
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] == tatget - nums[k]){
                    tmp[0] = nums[i];
                    tmp[1] = nums[j];
                    tmp[2] = nums[k];
                    vec_return.push_back(tmp);
                    k--;
                }
                else if (nums[i] + nums[j] < tatget - nums[k])
                    continue;
                else{//nums[i] + nums[j] > tatget - nums[k]
                    k--;
                    j--;
                }
            }
        }
        return vec_return;
    }
    void InsertSort(vector<int>& nums){
        int i, j, tmp;
        int n = nums.size();
        for (i = 1; i < n; i++){
            tmp = nums[i];
            for (j = i - 1; j != -1 && nums[j] > tmp; j--){
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = tmp;
        }
    }
};
