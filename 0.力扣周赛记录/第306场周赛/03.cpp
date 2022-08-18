/*
2375. 根据模式串构造最小数字
给你下标从 0 开始、长度为 n 的字符串 pattern ，它包含两种字符，'I' 表示 上升 ，'D' 表示 下降 。

你需要构造一个下标从 0 开始长度为 n + 1 的字符串，且它要满足以下条件：

num 包含数字 '1' 到 '9' ，其中每个数字 至多 使用一次。
如果 pattern[i] == 'I' ，那么 num[i] < num[i + 1] 。
如果 pattern[i] == 'D' ，那么 num[i] > num[i + 1] 。
请你返回满足上述条件字典序 最小 的字符串 num。

示例 1：

输入：pattern = "IIIDIDDD"
输出："123549876"
解释：
下标 0 ，1 ，2 和 4 处，我们需要使 num[i] < num[i+1] 。
下标 3 ，5 ，6 和 7 处，我们需要使 num[i] > num[i+1] 。
一些可能的 num 的值为 "245639871" ，"135749862" 和 "123849765" 。
"123549876" 是满足条件最小的数字。
注意，"123414321" 不是可行解因为数字 '1' 使用次数超过 1 次。
示例 2：

输入：pattern = "DDD"
输出："4321"
解释：
一些可能的 num 的值为 "9876" ，"7321" 和 "8742" 。
"4321" 是满足条件最小的数字。
*/
class Solution3 {
public:
    string smallestNumber(string pattern) {
        int n = 2;
        string ans = "1";
        stack<char> temp;
        for (int i = 0; i < pattern.size(); i++) {
            if (pattern[i] == 'I') {
                ans.push_back(n + '0');
                n++;
            }
            else { // i == 'D'
                temp.push(ans.back());
                ans.pop_back();
                temp.push(n + '0');
                n++;
                for (i++; i < pattern.size() && pattern[i] == 'D'; i++) {
                    temp.push(n + '0');
                    n++;
                }
                if (i < pattern.size())
                    i--;
                while (!temp.empty()) {
                    ans.push_back(temp.top());
                    temp.pop();
                }
            }
        }
        return ans;
    }
};
