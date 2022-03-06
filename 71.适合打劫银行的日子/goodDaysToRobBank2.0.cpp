class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> ans;
        if (time == 0){
            for (int i = 0; i < security.size(); i++)
                ans.push_back(i);
            return ans;
        }
        if (time * 2 > security.size())
            return ans;
        int time_temp;
        bool S;
        if (time == 1){
            for (int i = time; i < security.size() - 1; i++){
                S = true;
                if (security[i + 1] < security[i])
                    S = false;
                if (security[i - 1] < security[i])
                    S = false;
                if (S == true)
                    ans.push_back(i);
            }
            return ans;
        }
        for (int i = time; i < security.size() - time; i++){
            S = true;
            for (int j = i, time_temp = time; time_temp != 0; time_temp--, j++){
                if (security[j + 1] >= security[j])
                    continue;
                else {
                    S = false;
                    break;
                }
            }
            if (S == false)
                continue;
            for (int j = i, time_temp = time; time_temp != 0; time_temp--, j--){
                if (security[j - 1] >= security[j])
                    continue;
                else {
                    S = false;
                    break;
                }
            }
            if (S == false)
                continue;
            ans.push_back(i);
        }
        return ans;
    }
};
