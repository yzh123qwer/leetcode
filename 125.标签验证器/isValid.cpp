/*
591. 标签验证器
给定一个表示代码片段的字符串，你需要实现一个验证器来解析这段代码，并返回它是否合法。合法的代码片段需要遵守以下的所有规则：

代码必须被合法的闭合标签包围。否则，代码是无效的。
闭合标签（不一定合法）要严格符合格式：<TAG_NAME>TAG_CONTENT</TAG_NAME>。其中，<TAG_NAME>是起始标签，</TAG_NAME>是结束标签。起始和结束标签中的 TAG_NAME 应当相同。当且仅当 TAG_NAME 和 TAG_CONTENT 都是合法的，闭合标签才是合法的。
合法的 TAG_NAME 仅含有大写字母，长度在范围 [1,9] 之间。否则，该 TAG_NAME 是不合法的。
合法的 TAG_CONTENT 可以包含其他合法的闭合标签，cdata （请参考规则7）和任意字符（注意参考规则1）除了不匹配的<、不匹配的起始和结束标签、不匹配的或带有不合法 TAG_NAME 的闭合标签。否则，TAG_CONTENT 是不合法的。
一个起始标签，如果没有具有相同 TAG_NAME 的结束标签与之匹配，是不合法的。反之亦然。不过，你也需要考虑标签嵌套的问题。
一个<，如果你找不到一个后续的>与之匹配，是不合法的。并且当你找到一个<或</时，所有直到下一个>的前的字符，都应当被解析为 TAG_NAME（不一定合法）。
cdata 有如下格式：<![CDATA[CDATA_CONTENT]]>。CDATA_CONTENT 的范围被定义成 <![CDATA[ 和后续的第一个 ]]>之间的字符。
CDATA_CONTENT 可以包含任意字符。cdata 的功能是阻止验证器解析CDATA_CONTENT，所以即使其中有一些字符可以被解析为标签（无论合法还是不合法），也应该将它们视为常规字符。
合法代码的例子:

输入: "<DIV>This is the first line <![CDATA[<div>]]></DIV>"

输出: True

解释: 

代码被包含在了闭合的标签内： <DIV> 和 </DIV> 。

TAG_NAME 是合法的，TAG_CONTENT 包含了一些字符和 cdata 。 

即使 CDATA_CONTENT 含有不匹配的起始标签和不合法的 TAG_NAME，它应该被视为普通的文本，而不是标签。

所以 TAG_CONTENT 是合法的，因此代码是合法的。最终返回True。


输入: "<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"

输出: True

解释:

我们首先将代码分割为： start_tag|tag_content|end_tag 。

start_tag -> "<DIV>"

end_tag -> "</DIV>"

tag_content 也可被分割为： text1|cdata|text2 。

text1 -> ">>  ![cdata[]] "

cdata -> "<![CDATA[<div>]>]]>" ，其中 CDATA_CONTENT 为 "<div>]>"

text2 -> "]]>>]"


start_tag 不是 "<DIV>>>" 的原因参照规则 6 。
cdata 不是 "<![CDATA[<div>]>]]>]]>" 的原因参照规则 7 。
不合法代码的例子:

输入: "<A>  <B> </A>   </B>"
输出: False
解释: 不合法。如果 "<A>" 是闭合的，那么 "<B>" 一定是不匹配的，反之亦然。

输入: "<DIV>  div tag is not closed  <DIV>"
输出: False

输入: "<DIV>  unmatched <  </DIV>"
输出: False

输入: "<DIV> closed tags with invalid tag name  <b>123</b> </DIV>"
输出: False

输入: "<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>"
输出: False

输入: "<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>"
输出: False
*/
class Solution {
    bool tag_name(string name) {
        if (name.size() == 0)
            return false;
        if (name.size() > 9)
            return false;
        for (int ii = 0; ii < name.size(); ii++) {
            if (name[ii] < 'A' || name[ii] > 'Z')
                return false;
        }
        return true;
    }
    bool tag_name(string start, string end) {
        if (tag_name(end) == false)
            return false;
        if (start.size() != end.size())
            return false;
        for (int ii = 0; ii < start.size(); ii++) {
            if (start[ii] != end[ii])
                return false;
        }
        return true;
    }
    bool tag_content(int i, int j, string& code) {
        // 将tag_centent拆分成多个名字片段和语句，跳过CDATA
        stack<string> t_name;
        string temp_name;
        for (int ii = i; ii <= j; ii++) {
            if (code[ii] == '<') {
                if (ii + 1 <= j) {
                    if (code[ii + 1] == '!') { // 出现CDATA
                        if (cdata(ii, code) == false)
                            return false;
                    }
                    else if (code[ii + 1] == '/') { // 出现标签名称，末尾
                        for (ii += 2; ii <= j; ii++) {
                            if (code[ii] == '>')
                                break;
                            temp_name.push_back(code[ii]);
                        }
                        if (t_name.empty() == true) // 先出现标签末尾
                            return false;
                        if (tag_name(t_name.top(), temp_name) == true) {
                            t_name.pop();
                            temp_name.clear();
                        }
                        else
                            return false;
                    }
                    else {
                        for (ii += 1; ii <= j; ii++) {
                            if (code[ii] == '>')
                                break;
                            temp_name.push_back(code[ii]);
                        }
                        if (tag_name(temp_name) == true) { // 名字合法
                            t_name.push(temp_name);
                            temp_name.clear();
                        }
                        else
                            return false;
                    }
                }
                else
                    return false;
            }
        }
        if (t_name.empty() == true)
            return true;
        return false;
    }
    bool cdata(int &ii, string& code) {
        ii += 2;
        if (!(ii < code.size() && code[ii++] == '['))
            return false;
        if (!(ii < code.size() && code[ii++] == 'C'))
            return false;
        if (!(ii < code.size() && code[ii++] == 'D'))
            return false;
        if (!(ii < code.size() && code[ii++] == 'A'))
            return false;
        if (!(ii < code.size() && code[ii++] == 'T'))
            return false;
        if (!(ii < code.size() && code[ii++] == 'A'))
            return false;
        if (!(ii < code.size() && code[ii++] == '['))
            return false;
        for (; ii < code.size(); ii++) {
            if (code[ii] == ']') {
                if (ii + 1 < code.size() && code[ii + 1] == ']') {
                    if (ii + 2 < code.size() && code[ii + 2] == '>')
                        return true;
                }
            }
        }
        return false;
    }

public:
    bool isValid(string code) {
        if (code.size() < 7) // 最小的合法标签为<A></A>，7个字符
            return false;
        if (code[0] != '<')
            return false;
        string _start, _end;
        int i, j;
        for (int ii = 1; ii < code.size(); ii++) {
            if (code[ii] != '>')
                _start.push_back(code[ii]);
            else {
                i = ii + 1;
                break;
            }
        }
        if (tag_name(_start) == false)
            return false;
        if (code.back() != '>' || code[code.size() - _start.size() - 2] != '/' || code[code.size() - _start.size() - 3] != '<')
            return false;
        for (int ii = code.size() - 1 - _start.size(); ii < code.size() - 1; ii++)
            _end.push_back(code[ii]);
        if (tag_name(_start, _end) == false)
            return false;
        j = code.size() - _start.size() - 4;
        if (tag_content(i, j, code) == false)
            return false;
        return true;
    }
};
