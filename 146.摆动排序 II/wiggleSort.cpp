/*
324. 摆动排序 II
给你一个整数数组 nums，将它重新排列成 nums[0] < nums[1] > nums[2] < nums[3]... 的顺序。

你可以假设所有输入数组都可以得到满足题目要求的结果。

 

示例 1：

输入：nums = [1,5,1,1,6,4]
输出：[1,6,1,5,1,4]
解释：[1,4,1,5,1,6] 同样是符合题目要求的结果，可以被判题程序接受。
示例 2：

输入：nums = [1,3,2,2,3,1]
输出：[2,3,1,3,1,2]
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 1)
            return;
        vector<int> T(5001, 0);
        for (int i = 0; i < nums.size(); i++){
            T[nums[i]] += 1;
        }
        int T_i = 5000;
        int nums_i = 1;
        while (true){
            if (T[T_i] == 0){
                T_i--;
                continue;
            }
            else{ // T[T_i] != 0
                nums[nums_i] = T_i;;
                T[T_i]--;
                nums_i += 2;
                if (nums_i >= nums.size()){
                    if (nums_i % 2 == 0)
                        break;
                    else 
                        nums_i = 0;
                }
            }
        }
        return;
    }
};
