/*
393. UTF-8 编码验证
给定一个表示数据的整数数组 data ，返回它是否为有效的 UTF-8 编码。

UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：

对于 1 字节 的字符，字节的第一位设为 0 ，后面 7 位为这个符号的 unicode 码。
对于 n 字节 的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为 0 ，后面字节的前两位一律设为 10 。剩下的没有提及的二进制位，全部为这个符号的 unicode 码。
这是 UTF-8 编码的工作方式：

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
注意：输入是整数数组。只有每个整数的 最低 8 个有效位 用来存储数据。这意味着每个整数只表示 1 字节的数据。

 

示例 1：

输入：data = [197,130,1]
输出：true
解释：数据表示字节序列:11000101 10000010 00000001。
这是有效的 utf-8 编码，为一个 2 字节字符，跟着一个 1 字节字符。
示例 2：

输入：data = [235,140,4]
输出：false
解释：数据表示 8 位的序列: 11101011 10001100 00000100.
前 3 位都是 1 ，第 4 位为 0 表示它是一个 3 字节字符。
下一个字节是开头为 10 的延续字节，这是正确的。
但第二个延续字节不以 10 开头，所以是不符合规则的。
*/
class Solution {
public:
    vector<int> two_n = { 1, 2, 4, 8, 16, 32, 64, 128 };
    bool validUtf8(vector<int>& data) {
        vector<string> str_data;
        for (auto i : data)
            str_data.push_back(int_str(i));
        int i, j;
        for (i = 0; i < str_data.size(); i++){
            for (j = 0; j < 8 && str_data[i][j] == '1'; j++);
            if (j > 4 || j == 1)
                return false;
            if (j == 0) {
                if (i == str_data.size() - 1)
                    return true;
                else
                    continue;
            }
            if (j != 0 && i == str_data.size() - 1)
                return false;
            for (i = i + 1; j != 1; j--, i++){
                if (i == str_data.size())
                    return false;
                if (str_data[i][0] == '1' && str_data[i][1] == '0')
                    continue;
                else 
                    return false;
            }
            i--;
        }
        return true;
    }
    string int_str(int x){
        string ans;
        int temp;
        for (int i = 7; i != -1; i--){
            temp = x / two_n[i];
            ans = ans + to_string(temp);
            x = x - temp * two_n[i];
        }
        return ans;
    }
};
