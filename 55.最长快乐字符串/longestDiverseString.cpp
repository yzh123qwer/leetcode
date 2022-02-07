/*
1405. 最长快乐字符串
如果字符串中不含有任何 'aaa'，'bbb' 或 'ccc' 这样的字符串作为子串，那么该字符串就是一个「快乐字符串」。

给你三个整数 a，b ，c，请你返回 任意一个 满足下列全部条件的字符串 s：

s 是一个尽可能长的快乐字符串。
s 中 最多 有a 个字母 'a'、b 个字母 'b'、c 个字母 'c' 。
s 中只含有 'a'、'b' 、'c' 三种字母。
如果不存在这样的字符串 s ，请返回一个空字符串 ""。

 

示例 1：

输入：a = 1, b = 1, c = 7
输出："ccaccbcc"
解释："ccbccacc" 也是一种正确答案。
示例 2：

输入：a = 2, b = 2, c = 1
输出："aabbc"
示例 3：

输入：a = 7, b = 1, c = 0
输出："aabaa"
解释：这是该测试用例的唯一正确答案。
*/
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string s_return = "";
        pair<int, char> tmp;
        tmp = max(a, b, c);
        if (tmp.second == 'a'){
            if (tmp.first >= 2){
                s_return.push_back('a');
                s_return.push_back('a');
                a -= 2;
            }
            else if (tmp.first == 1){
                s_return.push_back('a');
                a--;
            }
            else {
                return s_return;
            }
        }
        else if (tmp.second == 'b'){
            if (tmp.first >= 2){
                s_return.push_back('b');
                s_return.push_back('b');
                b -= 2;
            }
            else if (tmp.first == 1){
                s_return.push_back('b');
                b--;
            }
            else {
                return s_return;
            }
        }
        else {//tmp.second == 'c'
            if (tmp.first >= 2){
                s_return.push_back('c');
                s_return.push_back('c');
                c -= 2;
            }
            else if (tmp.first == 1){
                s_return.push_back('c');
                c--;
            }
            else {
                return s_return;
            }
        }
        for (tmp = max(a, b, c); tmp.first != 0; tmp = max(a, b, c)){
            if (tmp.second == 'a'){
                if (tmp.first >= 2){
                    if (s_return.back() != 'a'){
                        s_return.push_back('a');
                        s_return.push_back('a');
                        a -= 2;
                    }
                    else {
                        if (b > c){
                            s_return.push_back('b');
                            b--;
                        }
                        else {//c <= b
                            if (c == 0)
                                return s_return;
                            else {
                                s_return.push_back('c');
                                c--;
                            }
                        }
                    }
                }
                else {//tmp.first == 1
                    if (s_return.back() != 'a'){
                        s_return.push_back('a');
                        a--;
                    }
                    else {
                        if (b != 0){
                            s_return.push_back('b');
                            b--;
                        }
                        else if (c != 0){
                            s_return.push_back('c');
                            c--;
                        }
                        else {//b = c == 0
                            return s_return;
                        }
                    }
                }
            }
            else if (tmp.second == 'b'){
                if (tmp.first >= 2){
                    if (s_return.back() != 'b'){
                        s_return.push_back('b');
                        s_return.push_back('b');
                        b -= 2;
                    }
                    else {
                        if (a > c){
                            s_return.push_back('a');
                            a--;
                        }
                        else {//c <= a
                            if (c == 0)
                                return s_return;
                            else {
                                s_return.push_back('c');
                                c--;
                            }
                        }
                    }
                }
                else {//tmp.first == 1
                    if (s_return.back() != 'b'){
                        s_return.push_back('b');
                        b--;
                    }
                    else {
                        if (a != 0){
                            s_return.push_back('a');
                            a--;
                        }
                        else if (c != 0){
                            s_return.push_back('c');
                            c--;
                        }
                        else {//a = c == 0
                            return s_return;
                        }
                    }
                }
            }
            else {
                if (tmp.first >= 2){
                    if (s_return.back() != 'c'){
                        s_return.push_back('c');
                        s_return.push_back('c');
                        c -= 2;
                    }
                    else {
                        if (a > b){
                            s_return.push_back('a');
                            a--;
                        }
                        else {//a <= b
                            if (b == 0)
                                return s_return;
                            else {
                                s_return.push_back('b');
                                b--;
                            }
                        }
                    }
                }
                else {//tmp.first == 1
                    if (s_return.back() != 'c'){
                        s_return.push_back('c');
                        c--;
                    }
                    else {
                        if (a != 0){
                            s_return.push_back('a');
                            a--;
                        }
                        else if (b != 0){
                            s_return.push_back('b');
                            b--;
                        }
                        else {//a = b == 0
                            return s_return;
                        }
                    }
                }
            }
        }
        return s_return;
    }
private:
    pair<int, char> max(int a, int b, int c){//选取数量最多的字符
        if (a >= b){
            if (a >= c)
                return make_pair(a, 'a');
            else //a < c
                return make_pair(c, 'c');
        }
        else {// b > a
            if (b >= c)
                return make_pair(b, 'b');
            else  // b < c
                return make_pair(c, 'c');
        }
    }
};
