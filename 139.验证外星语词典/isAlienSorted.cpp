/*
953. 验证外星语词典
某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

 

示例 1：

输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
输出：true
解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
示例 2：

输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
输出：false
解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
示例 3：

输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
输出：false
解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
*/
class Solution {
    bool fun(string s1, string s2, const unordered_map<char, int> &hash_order){
      // 输入单词1和单词2，以及外星字典序，判断单词1是否该排在单词2之前
        int temp_order_i1;
        int temp_order_i2;
        for (int i = 0; i < s1.size(); i++){
            temp_order_i1 = hash_order.find(s1[i])->second;
            if (i == s2.size())
                return false;
            temp_order_i2 = hash_order.find(s2[i])->second;
            if (temp_order_i1 > temp_order_i2)
                return false;
            else if (temp_order_i1 < temp_order_i2)
                return true;
            else // temp_order_i1 == temp_order_i2
                continue;    
        }
        return true;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hash_order;
        for (int i = 0; i < order.size(); i++){
            hash_order.insert(make_pair(order[i], i + 1));
        }
        for (int i = 1; i < words.size(); i++){
            if (fun(words[i - 1], words[i], hash_order) == true)
                continue;
            else 
                return false;
        }
        return true;
    }
};
