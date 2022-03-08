class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> plate_nums(s.size(), 0);
        for (int i = 0, sum = 0; i < s.size(); i++){
            if (s[i] == '*'){
                sum++;
                plate_nums[i] = sum;
            }
            else // s[i] == '|'
                plate_nums[i] = sum;
        }
        vector<int> candle;
        candle.push_back(-1);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '|'){
                candle.push_back(i);
            }
        }
        candle.push_back(-1);
        vector<vector<int>> plate(s.size(), vector<int>(2, -2)); // -1已经表示没有蜡烛，-2表示未被定义
        for (int i = 0, j = 0; i < s.size(); i++){
            if (s[i] == '*'){
                plate[i][0] = candle[j];
                plate[i][1] = candle[j + 1];
            }
            else{ // s[i] == '|'
                j++;
            }
        }
        int left, right;
        vector<int> ans;
        for (auto i : queries){
            if (s[i[0]] == '|')
                left = i[0];
            else 
                left = plate[i[0]][1];
            if (s[i[1]] == '|')
                right = i[1];
            else 
                right = plate[i[1]][0];
            if (left >= right || (left == -1 || right == -1))
                ans.push_back(0);
            else
                ans.push_back(plate_nums[right] - plate_nums[left]);
        }
        return ans;
    }
};
