/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
*/
bool isPalindrome(int x)
{
    if (x == 0)
        return 1;
    else if (x < 0)
        return 0;
    else 
{
    if(x % 10 == 0)
        return 0;
    else
    {
        int digit[10];
        int i = 0;
        while (x != 0)
        {
            digit[i++] = x % 10;
            x = x / 10;
        }
        int m,n;
        for (m = 0, n = i - 1; ; m++, n--)
        {
            if (digit[m] != digit[n])
                return 0;
            if(m == n || m + 1 == n)
                break;
        }
        return 1;
    }
}
}
