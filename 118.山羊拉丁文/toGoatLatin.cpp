/*
824. 山羊拉丁文
给你一个由若干单词组成的句子 sentence ，单词间由空格分隔。每个单词仅由大写和小写英文字母组成。

请你将句子转换为 “山羊拉丁文（Goat Latin）”（一种类似于 猪拉丁文 - Pig Latin 的虚构语言）。山羊拉丁文的规则如下：

如果单词以元音开头（'a', 'e', 'i', 'o', 'u'），在单词后添加"ma"。
例如，单词 "apple" 变为 "applema" 。
如果单词以辅音字母开头（即，非元音字母），移除第一个字符并将它放到末尾，之后再添加"ma"。
例如，单词 "goat" 变为 "oatgma" 。
根据单词在句子中的索引，在单词最后添加与索引相同数量的字母'a'，索引从 1 开始。
例如，在第一个单词后添加 "a" ，在第二个单词后添加 "aa" ，以此类推。
返回将 sentence 转换为山羊拉丁文后的句子。

 

示例 1：

输入：sentence = "I speak Goat Latin"
输出："Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
示例 2：

输入：sentence = "The quick brown fox jumped over the lazy dog"
输出："heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
*/
class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans;
        string temp;
        int j = 1;
        for (int i = 0; i < sentence.size(); i++){
            if (sentence[i] == ' '){
                fun1(temp);
                for (int ii = 0; ii < j; ii++)
                    temp.push_back('a');
                ans += temp;
                ans.push_back(' ');
                temp.clear();
                j++;
            }
            else{
                temp.push_back(sentence[i]);
            }
        }
        if (sentence.back() == ' '){
            ans.pop_back();
            return ans;
        }
        fun1(temp);
        ans += temp;
        for (int ii = 0; ii < j; ii++)
            ans.push_back('a');
        return ans;
    }
private:
    void fun1(string &s){
        if (aeiou(s[0]) == true){
            s.push_back('m');
            s.push_back('a');
            return;
        }
        else {
            if (s.size() == 1){
                s.push_back('m');
                s.push_back('a');
                return;
            }
            string ans;
            for (int i = 1; i < s.size(); i++){
                ans.push_back(s[i]);
            }
            ans.push_back(s[0]);
            ans.push_back('m');
            ans.push_back('a');
            s = ans;
            return;
        }
    }

    bool aeiou(char a){
        if (a == 'A' || a == 'a')
            return true;
        else if (a == 'E' || a == 'e')
            return true;
        else if (a == 'I' || a == 'i')
            return true;
        else if (a == 'O' || a == 'o')
            return true;
        else if (a == 'U' || a == 'u')
            return true;
        else 
            return false;
    }
};
