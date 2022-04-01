/*
954. 二倍数对数组
给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足 “对于每个 0 <= i < len(arr) / 2，都有 arr[2 * i + 1] = 2 * arr[2 * i]” 时，返回 true；否则，返回 false。

 

示例 1：

输入：arr = [3,1,3,6]
输出：false
示例 2：

输入：arr = [2,1,2,6]
输出：false
示例 3：

输入：arr = [4,-2,2,-4]
输出：true
解释：可以用 [-2,-4] 和 [2,4] 这两组组成 [-2,-4,2,4] 或是 [2,4,-2,-4]
*/
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> hash;
        for (auto i : arr) {
            if (hash.find(i) == hash.end())
                hash.insert(make_pair(i, 1));
            else
                hash.find(i)->second += 1;
        }
        int ans = arr.size() / 2;
        for (auto i : arr) {
            if (i == 0) {
                if (hash.find(i)->second > 1) {
                    while (hash.find(i)->second > 1) {
                        ans--;
                        hash.find(i)->second -= 2;
                    }
                }
                continue;
            }
            if (hash.find(i)->second != 0) {
                if (hash.find(2 * i) != hash.end() && hash.find(2 * i)->second != 0) {
                    if (hash.find(2 * i)->second > hash.find(i)->second) {
                        ans -= hash.find(i)->second;
                        hash.find(2 * i)->second -= hash.find(i)->second;
                        hash.find(i)->second -= hash.find(i)->second;
                    }
                    else {
                        ans -= hash.find(2 * i)->second;
                        hash.find(i)->second -= hash.find(2 * i)->second;
                        hash.find(2 * i)->second -= hash.find(2 * i)->second;
                    }
                }
            }
        }
        if (ans == 0)
            return true;
        return false;
    }
};
