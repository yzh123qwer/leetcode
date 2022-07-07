/*
648. 单词替换
在英语中，我们有一个叫做 词根(root) 的概念，可以词根后面添加其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典 dictionary 和一个用空格分隔单词形成的句子 sentence。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。

 

示例 1：

输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"
示例 2：

输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
输出："a a b c"
*/
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> hash;
        for (int i = 0; i < dictionary.size(); i++){
            if (hash.find(dictionary[i]) == hash.end())
                hash.insert(dictionary[i]);
        }
        string word_temp;
        string ans;
        for (int i = 0; i < sentence.size(); i++){
            if (sentence[i] == ' '){
                ans += word_temp;
                ans.push_back(' ');
                word_temp.clear();
            }
            else {
                word_temp.push_back(sentence[i]);
                if (hash.find(word_temp) != hash.end()){
                    ans += word_temp;
                    ans.push_back(' ');
                    word_temp.clear();
                    while (sentence[i] != ' ' && i < sentence.size())
                        i++;
                }
            }
        }
        if (word_temp.size() != 0)
            ans += word_temp;
        else 
            ans.pop_back();
        return ans;
    }
};
