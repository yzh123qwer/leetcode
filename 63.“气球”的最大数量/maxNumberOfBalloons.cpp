/*
1189. “气球” 的最大数量
给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
示例 1：
输入：text = "nlaebolko"
输出：1

示例 2：
输入：text = "loonbalxballpoon"
输出：2

示例 3：
输入：text = "leetcode"
输出：0
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> char_nums(5, 0);//一次存储b a l o n出现次数
        for (auto i : text){
            if (i == 'b')
                char_nums[0] += 1;
            else if (i == 'a')
                char_nums[1] += 1;
            else if (i == 'l')
                char_nums[2] += 1;
            else if (i == 'o')
                char_nums[3] += 1;
            else if (i == 'n')
                char_nums[4] += 1;
            else 
                continue;
        }
        int ans, i;
        for (ans = 0, i = 0; ; ans++, i = 0){
            if (char_nums[i] > 0){
                char_nums[i] -= 1;
                i++;
            }
            else 
                return ans;
            if (char_nums[i] > 0){
                char_nums[i] -= 1;
                i++;
            }
            else 
                return ans;
            if (char_nums[i] > 1){
                char_nums[i] -= 2;
                i++;
            }
            else    
                return ans;
            if (char_nums[i] > 1){
                char_nums[i] -= 2;
                i++;
            }
            else 
                return ans;
            if (char_nums[i] > 0){
                char_nums[i] -= 1;
                i++;
            }
            else 
                return ans;
        }
    }
};
