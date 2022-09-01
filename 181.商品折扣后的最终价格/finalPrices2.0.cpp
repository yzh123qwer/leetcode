class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> S;
        vector<int> ans(prices.size(), 0);
        for (int i = 0; i < prices.size(); i++){
            if (S.empty())
                S.push(make_pair(prices[i], i));
            else {
                if (prices[i] > S.top().first){
                    S.push(make_pair(prices[i], i));
                }
                else {
                    while (!S.empty() && prices[i] <= S.top().first){
                        ans[S.top().second] = S.top().first - prices[i];
                        S.pop();
                    }
                    S.push(make_pair(prices[i], i));
                }
            }
        }
        while (!S.empty()){
            ans[S.top().second] = S.top().first;
            S.pop();
        }
        return ans;
    }
};
