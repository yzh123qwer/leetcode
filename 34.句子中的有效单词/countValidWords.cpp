class Solution {
public:
    int countValidWords(string sentence) {
        int n = sentence.size();
        int i, j;
        int token_nums = 0;
        int nums_ = 0;//用于记录一个token中'-'的数量
        bool S = true;//用于判断当前token是否是真确的
        for (i = 0; i <= n; i++) {
            if (sentence[i] <= 'z' && sentence[i] >= 'a') 
                continue;
            else if (sentence[i] == ' ') {
                if (i == 0){
                    for ( ; sentence[i + 1] == ' '; i++);
                    continue;
                }
                if (S == true) {
                    token_nums++;
                    nums_ = 0;
                    for (; sentence[i] == ' '; i++);
                    if (i == n)//末尾出现空格
                        break;
                    else
                        i--;//使其在下一个循环开始，i指向下一个taken的首字符
                }
                else { //S == false
                    for (; sentence[i] == ' '; i++);
                        if (i == n)
                            break;
                        else {
                            S = true;
                            nums_ = 0;
                            i--;
                        }
                }
            }
            else if (i == n) {
                if (S == true){
                    token_nums++;
                    nums_ = 0;
                }
            }
            else if (sentence[i] == '-') {
                nums_++;
                if (nums_++ > 1){
                    S = false;
                    continue;
                }
                if (i == 0 || sentence[i - 1] == ' ' || sentence[i + 1] == ' ' || i + 1 == n)
                    S = false;
            }
            else if (sentence[i] == ',' || sentence[i] == '.' || sentence[i] == '!') {
                if ((sentence[i + 1] == ' ' || i + 1 == n) && ((i == 0 || sentence[i - 1] <= 'z' && sentence[i - 1] >= 'a') || sentence[i - 1] == ' ')) {
                    if (S == true) {
                        token_nums++;
                        nums_ = 0;
                        for (i++; sentence[i] == ' '; i++);
                        if (i == n)//末尾出现空格
                            break;
                        else
                            i--;//使其在下一个循环开始，i指向下一个taken的首字符
                    }
                    else {
                        for (i++; sentence[i] == ' '; i++);
                        if (i == n)
                            break;
                        else {
                            S = true;
                            nums_ = 0;
                            i--;
                        }
                    }
                }
                else {
                    S = false;
                    continue;
                }
            }
            else {//sentence[i] == 数字
                S = false;
            }
        }
        return token_nums;
    }
};
