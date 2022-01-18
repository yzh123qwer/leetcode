/*
539. 最小时间差
给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

示例 1：

输入：timePoints = ["23:59","00:00"]
输出：1
示例 2：

输入：timePoints = ["00:00","23:59","00:00"]
输出：0
*/
int GetMin(char *time1, char *time2){
    int min1 = (time1[0] - 48) * 10 * 60 + (time1[1] - 48) * 60 + (time1[3] - 48) * 10 + (time1[4] - 48);
    int min2 = (time2[0] - 48) * 10 * 60 + (time2[1] - 48) * 60 + (time2[3] - 48) * 10 + (time2[4] - 48);
    int min_return;
    if (min1 > min2 ){
        min_return = min1 - min2;
        if (min_return > 720){
            min2 = min2 + 1440;
            return min2 - min1;
        }
        else
            return min_return;
    }
    else{
        min_return = min2 - min1;
        if (min_return > 720){
            min1 = min1 + 1440;
            return min1 - min2;
        }
        else
            return min_return;
    }
}
int findMinDifference(char ** timePoints, int timePointsSize){
    int i , j;
    int min_difference = 720;
    int difference_tmp;
    for (i = 0; i < timePointsSize; i++){
        for (j = i + 1; j < timePointsSize; j++){
            difference_tmp = subtraction(timePoints[i], timePoints[j]);
            if (difference_tmp < min_difference)
                min_difference = difference_tmp;
        }
    }
    return min_difference;
}
