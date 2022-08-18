/*
1224. 最大相等频率
给你一个正整数数组 nums，请你帮忙从该数组中找出能满足下面要求的 最长 前缀，并返回该前缀的长度：

从前缀中 恰好删除一个 元素后，剩下每个数字的出现次数都相同。
如果删除这个元素后没有剩余元素存在，仍可认为每个数字都具有相同的出现次数（也就是 0 次）。

 

示例 1：

输入：nums = [2,2,1,1,5,3,3,5]
输出：7
解释：对于长度为 7 的子数组 [2,2,1,1,5,3,3]，如果我们从中删去 nums[4] = 5，就可以得到 [2,2,1,1,3,3]，里面每个数字都出现了两次。
示例 2：

输入：nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
输出：13
*/
class Solution {
    bool fun(unordered_map<int, int>& count, unordered_map<int, int>& freq, int max_freq) {
        if (max_freq == 1) {
            return true;
        }
        if (freq.size() == 2) {
            if (freq.find(max_freq)->second == 1) {
                if (freq.find(1) != freq.end() && freq.find(1)->second == 1)
                    return true;
                if (freq.find(max_freq - 1) != freq.end())
                    return true;
                else
                    return false;
            }
            else {
                if (freq.find(1) != freq.end()) {
                    if (freq.find(1)->second == 1)
                        return true;
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        else if (freq.size() == 1) {
            if (freq.find(max_freq)->second == 1)
                return true;
            else
                return false;
        }
        else
            return false;
    }
public:
    int maxEqualFreq(vector<int>& nums) {
        unordered_map<int, int> count, freq;
        unordered_map<int, int>::iterator it;
        int freq_temp = 0;
        int max_freq = 0;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            it = count.find(nums[i]);
            if (it == count.end()) {
                count.insert(make_pair(nums[i], 1));
                freq_temp = 1;
            }
            else {
                it->second += 1;
                freq_temp = it->second;
            }
            if (freq_temp > max_freq)
                max_freq = freq_temp;
            it = freq.find(freq_temp);
            if (it == freq.end())
                freq.insert(make_pair(freq_temp, 1));
            else
                it->second += 1;
            freq_temp--;
            if (freq_temp != 0) {
                it = freq.find(freq_temp); // 这里为了删去之前的频率出现次数，因此一定存在。
                if (it->second == 1)
                    freq.erase(it);
                else
                    it->second -= 1;
            }
            if (fun(count, freq, max_freq) == true)
                ret = i + 1;
        }
        return ret;
    }
};
