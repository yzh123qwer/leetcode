/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。*/
int lengthOfLongestSubstring(char * s)
{
    if (s[0] == '\0')
        return 0;
    else if (s[1] == '\0')
        return 1;
    else if (s[2] == '\0')
    {
        if(s[0] == s[1])
            return 1;
        else
            return 2;
    }
    else
    {
        int m, n, i, most_length = 0, length = 0, s_length = 0;
        for (i = 0; s[i] != 0; i++);
        s_length = i;
        int Y;
        for (m = 0; s_length - m > most_length; m = n)
        {
            for (n = m + 1; s[n] != '\0'; n++)
            {
                for(i = m, Y = 1; i != n; i++)
                {
                    Y = (s[n] != s[i]);
                    if (Y == 1)
                        continue;
                    else 
                    {
                        length = n - m;
                        break;
                    }
                }
                if (Y != 1)
                    break;
            }
            if(length > most_length)
                most_length = length;
        }
        return most_length;
    }
}
