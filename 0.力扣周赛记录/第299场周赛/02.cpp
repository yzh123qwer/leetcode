/*
6100. 统计放置房子的方式数
一条街道上共有 n * 2 个 地块 ，街道的两侧各有 n 个地块。每一边的地块都按从 1 到 n 编号。每个地块上都可以放置一所房子。

现要求街道同一侧不能存在两所房子相邻的情况，请你计算并返回放置房屋的方式数目。由于答案可能很大，需要对 109 + 7 取余后再返回。

注意，如果一所房子放置在这条街某一侧上的第 i 个地块，不影响在另一侧的第 i 个地块放置房子。

 

示例 1：

输入：n = 1
输出：4
解释：
可能的放置方式：
1. 所有地块都不放置房子。
2. 一所房子放在街道的某一侧。
3. 一所房子放在街道的另一侧。
4. 放置两所房子，街道两侧各放置一所。
示例 2：


输入：n = 2
输出：9
解释：如上图所示，共有 9 种可能的放置方式。
*/
class Solution_ {
public:
    int countHousePlacements(int n) {
        pair<long long, long long> last; // 使用first表示空，second表示有房子
        last.first = 1;
        last.second = 1;
        pair<long long, long long> next;
        next.first = 1;
        next.second = 1;
        for (int i = 1; i < n; i++) {
            next.first = (last.first + last.second) % 1000000007;
            next.second = last.first;
            last = next;
        }
        long long sum = next.first + next.second;
        sum = (sum * sum);
        sum = sum % 1000000007;
        int ans = sum;
        return ans;
    }
};

class Solution {
public:
    int countHousePlacements(int n) {
        if (n == 1)
            return 4;
        if (n == 2)
            return 9;
        long long last_last = 2;
        long long last = 3;
        long long now;
        for (int i = 3; i <= n; i++) {
            now = (last_last + last) % 1000000007;
            last_last = last;
            last = now;
        }
        now = now * now;
        now = now % 1000000007;
        int ans = now;
        return ans;
    }
};
