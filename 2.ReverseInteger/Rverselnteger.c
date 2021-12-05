/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
*/
int reverse(int x)
{
    if(x == 0)
        return 0;
    if(x < 0)
    {
        x = 0 - x;
        int i, k = 1;
        int answer = 0;
        for(i = 1; ; i = i * 10)
        {
            if (x / i == 0)
                break;
        }
        for(k = 1, i = i / 10; i != 0; i = i / 10, k = k * 10)
        {
            answer = (x / i) * k + answer;
            x = x - (x / i) * i;
        }
        return 0 - answer;
    }
    else
    {
        int i, k = 1;
        int answer = 0;
        for(i = 1; ; i = i * 10)
        {
            if (x / i == 0)
                break;
        }
        for(k = 1, i = i / 10; i != 0; i = i / 10, k = k * 10)
        {
            answer = (x / i) * k + answer;
            x = x - (x / i) * i;
        }
        return answer;
    }
}
