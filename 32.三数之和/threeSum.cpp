/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
示例 2：

输入：nums = []
输出：[]
示例 3：

输入：nums = [0]
输出：[]
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<int> nums1_hash;//正数
        unordered_set<int> nums2_hash;//负数
        vector<int> nums1;
        vector<int> nums2;
        int zero = 0;
        for (int i : nums) {
            if (i > 0){
                nums1.push_back(i);
                nums1_hash.insert(i);
            }
            else if (i < 0){
                nums2.push_back(-i);
                nums2_hash.insert(-i);//希望哈希表中存储的均为正数
            }
            else //i = 0
                zero++;
        }
        InsertSort(nums1);
        InsertSort(nums2);
        vector<vector<int>> nums_return;
        vector<int> tmp(3);
        vector<int>::iterator the1, the2;
        unordered_set<int> nums_tmp, nums_tmp2;
        for (the1 = nums1.begin(); the1 != nums1.end(); the1++) {
            if (nums_tmp.find(*the1) == nums_tmp.end()){
                for (the2 = the1 + 1; the2 != nums1.end(); the2++) {
                    if (nums_tmp2.find(*the2) == nums_tmp2.end()){
                        if (nums2_hash.find(*the1 + *the2) != nums2_hash.end()) {
                            tmp[0] = *the1;
                            tmp[1] = *the2;
                            tmp[2] = -(*the1 + *the2);
                            nums_return.push_back(tmp);
                        }
                        nums_tmp2.insert(*the2);
                    }
                    else
                        continue;
                }
                nums_tmp2.clear();
                nums_tmp.insert(*the1);
            }
            else
                continue;
        }
        nums_tmp.clear();
        for (the1 = nums2.begin(); the1 != nums2.end(); the1++) {
            if (nums_tmp.find(*the1) == nums_tmp.end()){
                for (the2 = the1 + 1; the2 != nums2.end(); the2++) {
                    if (nums_tmp2.find(*the2) == nums_tmp2.end()){
                        if (nums1_hash.find(*the1 + *the2) != nums1_hash.end()) {
                            tmp[0] = -*the1;
                            tmp[1] = -*the2;
                            tmp[2] = *the1 + *the2;
                            nums_return.push_back(tmp);
                        }
                        nums_tmp2.insert(*the2);
                    }
                    else
                        continue;
                }
                nums_tmp2.clear();
                nums_tmp.insert(*the1);
            }
            else
                continue;
        }
        if (zero != 0) {
            unordered_set<int>::iterator the_hash1, the_hash2;
            for (the_hash1 = nums1_hash.begin(); the_hash1 != nums1_hash.end(); the_hash1++) {
                if (nums2_hash.find(*the_hash1) != nums2_hash.end()) {
                    tmp[0] = *the_hash1;
                    tmp[1] = -*the_hash1;
                    tmp[2] = 0;
                    nums_return.push_back(tmp);
                }
            }
        }
        if (zero >= 3){
            tmp[0] = tmp[1] = tmp[2] = 0;
            nums_return.push_back(tmp);
        }
        return nums_return;
    }
private:
    void InsertSort(vector<int>& nums){
        int i, j, tmp;
        int n = nums.size();
        for (i = 1; i < n; i++){
            tmp = nums[i];
            for (j = i - 1; j != -1 && nums[j] > tmp; j--)
                nums[j + 1] = nums[j];
            nums[j + 1] = tmp;
        }
    }
};
