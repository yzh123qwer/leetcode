/*
2461. 长度为 K 子数组中的最大和
给你一个整数数组 nums 和一个整数 k 。请你从 nums 中满足下述条件的全部子数组中找出最大子数组和：

子数组的长度是 k，且
子数组中的所有元素 各不相同 。
返回满足题面要求的最大子数组和。如果不存在子数组满足这些条件，返回 0 。

子数组 是数组中一段连续非空的元素序列。

 

示例 1：

输入：nums = [1,5,4,2,9,9,9], k = 3
输出：15
解释：nums 中长度为 3 的子数组是：
- [1,5,4] 满足全部条件，和为 10 。
- [5,4,2] 满足全部条件，和为 11 。
- [4,2,9] 满足全部条件，和为 15 。
- [2,9,9] 不满足全部条件，因为元素 9 出现重复。
- [9,9,9] 不满足全部条件，因为元素 9 出现重复。
因为 15 是满足全部条件的所有子数组中的最大子数组和，所以返回 15 。
示例 2：

输入：nums = [4,4,4], k = 3
输出：0
解释：nums 中长度为 3 的子数组是：
- [4,4,4] 不满足全部条件，因为元素 4 出现重复。
因为不存在满足全部条件的子数组，所以返回 0 。
*/
class Solution2 {
public:
	long long maximumSubarraySum(vector<int>& nums, int k) {
		if (k > nums.size())
			return 0;
		unordered_map<int, int> hash;
		int nums_same = 0;
		long long nums_sum = 0;
		long long ans = 0;
		for (int i = 0; i < k; i++) {
			nums_sum += nums[i];
			if (hash.find(nums[i]) == hash.end())
				hash.insert(make_pair(nums[i], 1));
			else {
				if (hash.find(nums[i])->second == 1) {
					nums_same++;
					hash.find(nums[i])->second += 1;
				}
				else 
					hash.find(nums[i])->second += 1;
			}
		}
		if (nums_same == 0)
			ans = nums_sum;
		for (int i = k; i < nums.size(); i++) {
			nums_sum += nums[i];
			if (hash.find(nums[i]) == hash.end())
				hash.insert(make_pair(nums[i], 1));
			else {
				if (hash.find(nums[i])->second == 1) {
					nums_same++;
					hash.find(nums[i])->second += 1;
				}
				else
					hash.find(nums[i])->second += 1;
			}
			nums_sum -= nums[i - k];
			if (hash.find(nums[i - k])->second == 1) 
				hash.erase(hash.find(nums[i - k]));
			else if (hash.find(nums[i - k])->second == 2){
				hash.find(nums[i - k])->second -= 1;
				nums_same--;
			}
			else 
				hash.find(nums[i - k])->second -= 1;
			if (nums_same == 0 && nums_sum > ans)
				ans = nums_sum;
		}
		return ans;
	}
};
