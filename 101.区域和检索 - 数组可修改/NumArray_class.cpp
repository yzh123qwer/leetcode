/*
307. 区域和检索 - 数组可修改
给你一个数组 nums ，请你完成两类查询。

其中一类查询要求 更新 数组 nums 下标对应的值
另一类查询要求返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 ，其中 left <= right
实现 NumArray 类：

NumArray(int[] nums) 用整数数组 nums 初始化对象
void update(int index, int val) 将 nums[index] 的值 更新 为 val
int sumRange(int left, int right) 返回数组 nums 中索引 left 和索引 right 之间（ 包含 ）的nums元素的 和 （即，nums[left] + nums[left + 1], ..., nums[right]）
 

示例 1：

输入：
["NumArray", "sumRange", "update", "sumRange"]
[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
输出：
[null, 9, null, 8]

解释：
NumArray numArray = new NumArray([1, 3, 5]);
numArray.sumRange(0, 2); // 返回 1 + 3 + 5 = 9
numArray.update(1, 2);   // nums = [1,2,5]
numArray.sumRange(0, 2); // 返回 1 + 2 + 5 = 8
*/
class NumArray {
public:
    vector<int> p_nums;
    vector<vector<int>> sum_nums;
    NumArray(vector<int>& nums) {
        p_nums = nums;
        sum_nums.resize(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sum_nums[i].resize(nums.size());
        }
        for (int i = 0; i < nums.size(); i++)
            sum_nums[i][i] = nums[i];
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                sum_nums[i][j] = sum_nums[i][j - 1] + nums[j];
            }
        }
    }

    void update(int index, int val) {
        int temp = p_nums[index];
        p_nums[index] = val;
        temp = val - temp;
        for (int i = 0; i <= index; i++)
            for (int j = index; j < p_nums.size(); j++)
                sum_nums[i][j] += temp;
    }

    int sumRange(int left, int right) {
        return sum_nums[left][right];
    }
};
