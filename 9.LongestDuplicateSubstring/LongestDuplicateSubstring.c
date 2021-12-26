/*
给你一个字符串 s ，考虑其所有 重复子串 ：即，s 的连续子串，在 s 中出现 2 次或更多次。这些出现之间可能存在重叠。

返回 任意一个 具有最长长度的重复子串。如果 s 不含重复子串，那么答案为 "" 。

 

示例 1：

输入：s = "banana"
输出："ana"
示例 2：

输入：s = "abcd"
输出：""
*/
char * longestDupSubstring(char * s)
{
    int x, y, m, n, k;
    //x, y判断重复字符，m, n判断最长重复子串
    int max_length = 0, length;
    for (y = 1; s[y] != '\0'; y++)
    {
        for (x = 0; x != y; x++)
        {
            if (s[x] == s[y])
            {
                for (m = x, n = y, length = 0; s[n] != '\0' && s[m] == s[n]; m++, n++, length++);
                if (length > max_length)
                {
                    k = m - length;
                    max_length = length;
                }
            }
        }
    }
    char* s_return = (char*)malloc(sizeof(char) * (max_length + 1));
    for (m = 0; m != max_length; m++, k++)
        s_return[m] = s[k];
    s_return[max_length] = '\0';
    return s_return;
}
