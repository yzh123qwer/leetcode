/*将字符串中的大小字母转换为小写字母，其他字符不做更改。*/
char * toLowerCase(char * s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] + 32;   
        i++;
    }
    return s;
}
