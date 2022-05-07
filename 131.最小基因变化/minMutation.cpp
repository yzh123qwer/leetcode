/*
433. 最小基因变化
基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。

给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

 

示例 1：

输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
输出：1
示例 2：

输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
输出：2
示例 3：

输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
输出：3
*/
class Solution {
    unordered_set<string> _bank;
    queue<string> q;
    void fun(string start){
        for (int i = 0; i < start.size(); i++){
            if (start[i] == 'A'){
                start[i] = 'G';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'C';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'T';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'A';
            }
            else if (start[i] == 'G'){
                start[i] = 'A';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'C';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'T';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'G';
            }
            else if (start[i] == 'C'){
                start[i] = 'A';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'G';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'T';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'C';
            }
            else { // start[i] == 'T'
                start[i] = 'A';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'G';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'C';
                if (_bank.find(start) != _bank.end())
                    q.push(start);
                start[i] = 'T';
            }
        }
    }
public:
    int minMutation(string start, string end, vector<string>& bank) {
        // unordered_set<string> _bank;
        for (auto i : bank)
            _bank.insert(i);
        if (_bank.find(end) == _bank.end())
            return -1;
        // queue<string> q;
        int ans = 0;
        fun(start);
        int q_size = q.size();
        while (!q.empty()){
            q_size = q.size();
            ans++;
            for (int i = 0; i < q_size; i++){
                if (q.front() == end)
                    return ans;
                fun(q.front());
                q.pop();
            }
        }
        return -1;
    }
};
