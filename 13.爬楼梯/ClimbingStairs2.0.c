int climbStairs(int n){
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else{
        int i, last, last2, answer;
        last2 = 1;
        last = 2;
        for (i = 3; i <= n; i++){
            answer = last2 + last;
            last2 = last;
            last = answer;
        }
        return answer;
    }
}
