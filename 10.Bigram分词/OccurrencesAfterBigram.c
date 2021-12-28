/*
给出第一个词 first 和第二个词 second，考虑在某些文本 text 中可能以 "first second third" 形式出现的情况，其中 second 紧随 first 出现，third 紧随 second 出现。

对于每种这样的情况，将第三个词 "third" 添加到答案中，并返回答案。

示例 1：

输入：text = "alice is a good girl she is a good student", first = "a", second = "good"
输出：["girl","student"]
示例 2：

输入：text = "we will we will rock you", first = "we", second = "will"
输出：["we","rock"]
 
提示：

1 <= text.length <= 1000
text 由小写英文字母和空格组成
text 中的所有单词之间都由 单个空格字符 分隔
1 <= first.length, second.length <= 10
first 和 second 由小写英文字母组成
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int string_difference(char* A, char* B)
//相同则返回1，不相同则返回0
{
    int i;
    for (i = 0; ; i++)
    {
        if (A[i] == '\0' && B[i] == '\0')
            return 1;
        else if (A[i] == B[i])
            continue;
        else
            return 0;
    }
}
int string_length(char* A)
{
    int i;
    for (i = 0; A[i] != '\0' && A[i] != 32; i++);
    return i;
}
char ** findOcurrences(char * text, char * first, char * second, int* returnSize)
{
    *returnSize = 0;
    int i, j, w1, w2;
    int k[10];//假定返回的单词数目小于等于10
    w1 = w2 = 0;
    char word1_temp[15], word2_temp[15];//假定句子中的单词长度小于等于14个字母
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] != 32)
        {
            word1_temp[w1++] = text[i];
        }
        else
        {
            word1_temp[w1] = '\0';
            if (string_difference(word1_temp, first) == 0)
                w1 = 0;
            else
            {
                for (j = i + 1; text[j] != 32 && text[j] != '\0'; j++)
                    word2_temp[w2++] = text[j];
                word2_temp[w2] = '\0';
                if (string_difference(word2_temp, second) == 0)
                    w1 = w2 = 0;
                else
                {
                    if (text[j] == 32)
                    {
                        k[*returnSize] = j + 1;
                        *returnSize = *returnSize + 1;
                        w1 = w2 = 0;
                    }
                    else
                        w1 = w2 = 0;
                }
            }
        }
    }
    int length;
    char** return_char = (char**)malloc(sizeof(char*) * (*returnSize));
    for (i = 0; i < *returnSize; i++)
    {
        length = string_length(&text[k[i]]);
        return_char[i] = (char*)malloc(sizeof(char) * (length + 1));
        for (j = 0; j < length; j++)
            return_char[i][j] = text[k[i] + j];
        return_char[i][length] = '\0';
    }
    return return_char;
}
