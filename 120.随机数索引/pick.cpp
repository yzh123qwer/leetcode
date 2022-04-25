/*
398. 随机数索引
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。 您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

示例:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) 应该返回索引 2,3 或者 4。每个索引的返回概率应该相等。
solution.pick(3);

// pick(1) 应该返回 0。因为只有nums[0]等于1。
solution.pick(1);
*/
class Solution {
    unordered_map<int, vector<int>> hash;
public:
    Solution(vector<int>& nums) {
        vector<int> temp (1, -1);
        for (int i = 0; i < nums.size(); i++){
            if (hash.find(nums[i]) == hash.end()){
                temp[0] = i;
                hash.insert(make_pair(nums[i], temp));
            }
            else {
                hash.find(nums[i])->second.push_back(i);
            }
        }
    }
    
    int pick(int target) {
        const vector<int> &temp = hash.find(target)->second;
        return temp[rand() % temp.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
