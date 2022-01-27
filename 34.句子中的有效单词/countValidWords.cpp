/*
2047. 句子中的有效单词数
句子仅由小写字母（'a' 到 'z'）、数字（'0' 到 '9'）、连字符（'-'）、标点符号（'!'、'.' 和 ','）以及空格（' '）组成。每个句子可以根据空格分解成 一个或者多个 token ，这些 token 之间由一个或者多个空格 ' ' 分隔。

如果一个 token 同时满足下述条件，则认为这个 token 是一个有效单词：

仅由小写字母、连字符和/或标点（不含数字）。
至多一个 连字符 '-' 。如果存在，连字符两侧应当都存在小写字母（"a-b" 是一个有效单词，但 "-ab" 和 "ab-" 不是有效单词）。
至多一个 标点符号。如果存在，标点符号应当位于 token 的 末尾 。
这里给出几个有效单词的例子："a-b."、"afad"、"ba-c"、"a!" 和 "!" 。

给你一个字符串 sentence ，请你找出并返回 sentence 中 有效单词的数目 。

 

示例 1：

输入：sentence = "cat and  dog"
输出：3
解释：句子中的有效单词是 "cat"、"and" 和 "dog"
示例 2：

输入：sentence = "!this  1-s b8d!"
输出：0
解释：句子中没有有效单词
"!this" 不是有效单词，因为它以一个标点开头
"1-s" 和 "b8d" 也不是有效单词，因为它们都包含数字
示例 3：

输入：sentence = "alice and  bob are playing stone-game10"
输出：5
解释：句子中的有效单词是 "alice"、"and"、"bob"、"are" 和 "playing"
"stone-game10" 不是有效单词，因为它含有数字
示例 4：

输入：sentence = "he bought 2 pencils, 3 erasers, and 1  pencil-sharpener."
输出：6
解释：句子中的有效单词是 "he"、"bought"、"pencils,"、"erasers,"、"and" 和 "pencil-sharpener."
*/
class Solution {
public:
    int countValidWords(string sentence) {
        int n = sentence.size();
        int i, j;
        int token_nums = 0;
        int nums_ = 0;//用于记录一个token中'-'的数量
        bool S = true;//用于判断当前token是否是真确的
        for (i = 0; i <= n; i++) {
            if (sentence[i] <= 'z' && sentence[i] >= 'a') 
                continue;
            else if (sentence[i] == ' ') {
                if (i == 0){
                    for ( ; sentence[i + 1] == ' '; i++);
                    continue;
                }
                if (S == true) {
                    token_nums++;
                    nums_ = 0;
                    for (; sentence[i] == ' '; i++);
                    if (i == n)//末尾出现空格
                        break;
                    else
                        i--;//使其在下一个循环开始，i指向下一个taken的首字符
                }
                else { //S == false
                    for (; sentence[i] == ' '; i++);
                        if (i == n)
                            break;
                        else {
                            S = true;
                            nums_ = 0;
                            i--;
                        }
                }
            }
            else if (i == n) {
                if (S == true){
                    token_nums++;
                    nums_ = 0;
                }
            }
            else if (sentence[i] == '-') {
                nums_++;
                if (nums_++ > 1){
                    S = false;
                    continue;
                }
                if (i == 0 || sentence[i - 1] == ' ' || sentence[i + 1] == ' ' || i + 1 == n)
                    S = false;
            }
            else if (sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '!') {
                if ((sentence[i + 1] == ' ' || i + 1 == n) && ((i == 0 || sentence[i - 1] <= 'z' && sentence[i - 1] >= 'a') || sentence[i - 1] == ' ')) {
                    if (S == true) {
                        token_nums++;
                        nums_ = 0;
                        for (i++; sentence[i] == ' '; i++);
                        if (i == n)//末尾出现空格
                            break;
                        else
                            i--;//使其在下一个循环开始，i指向下一个taken的首字符
                    }
                    else {
                        for (i++; sentence[i] == ' '; i++);
                        if (i == n)
                            break;
                        else {
                            S = true;
                            nums_ = 0;
                            i--;
                        }
                    }
                }
                else {
                    S = false;
                    continue;
                }
            }
            else {//sentence[i] == 数字
                S = false;
            }
        }
        return token_nums;
    }
};
