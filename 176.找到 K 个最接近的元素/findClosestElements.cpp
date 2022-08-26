/*
658. 找到 K 个最接近的元素
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b
 

示例 1：

输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]
示例 2：

输入：arr = [1,2,3,4,5], k = 4, x = -1
输出：[1,2,3,4]
*/
class Solution {
    int close_twonums(int a, int b){
        if (a > b)
            return a - b;
        else if (b > a)
            return b - a;
        else 
            return 0;
    }
    void ans_build(vector<int>& ans, int begin, int end, vector<int>& arr){
        for (int i = begin; i <= end; i++)
            ans.push_back(arr[i]);
        return;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == arr.size())
            return arr;
        int begin = 0;
        int end = k - 1;
        int sum = 0;
        vector<int> ans;
        for (int i = begin; i <= end; i++){
            sum = sum + close_twonums(arr[i], x);
        }
        if (sum == 0){
            ans_build(ans, begin, end, arr);
            return ans;
        }
        int temp_1 = 0;
        int temp_2 = 0;
        for (int i = 0; i < arr.size() - k; i++){
            temp_1 = close_twonums(arr[i], x);
            temp_2 = close_twonums(arr[i + k], x);
            if (temp_1 > temp_2){
                begin = i + 1;
                end = i + k;
                sum = sum - temp_1;
                sum = sum + temp_2;
                if (sum == 0){
                    ans_build(ans, begin, end, arr);
                    return ans;
                }
            }
            else if (temp_2 < temp_1){
                ans_build(ans, begin, end, arr);
                return ans;
            }
            else { // temp_1 == temp_2
                continue;
            }
        }
        ans_build(ans, begin, end, arr);
        return ans;
    }
};
