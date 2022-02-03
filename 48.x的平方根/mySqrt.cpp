/*
69. x 的平方根 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/
class Solution {
public:
    int mySqrt(int x) {
        int i, j;
        int mid;
        for (i = 0, j = x; i < j; ){
            mid = (i + j) / 2;
            if ((long long)mid * mid > x){
                if ((long long)(mid - 1) * (mid - 1) < x)
                    return mid - 1;
                    else {
                        j = mid - 1;
                        continue;
                    }
            }
            else if ((long long)mid * mid < x){
                if ((long long)(mid + 1) * (mid + 1) > x)
                    return mid;
                else {
                    i = mid + 1;
                }
            }
            else
                return mid;
        }
        return i;
    }
};
