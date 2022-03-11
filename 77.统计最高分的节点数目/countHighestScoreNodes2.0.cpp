class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<pair<int, pair<int, int>>> tree_node(n, make_pair(0, make_pair(-2, -2)));
        for (int i = 0; i < n; i++){
            tree_node[i].first++;
            for (int j = i; j != 0; j = parents[j], tree_node[j].first++){
                if (tree_node[parents[j]].second.first == j || tree_node[parents[j]].second.second == j);
                else if (tree_node[parents[j]].second.first == -2)
                    tree_node[parents[j]].second.first = j;
                else //tree_node[parents[j]].second.second == -2
                    tree_node[parents[j]].second.second = j;
            }
        }
        int max_num = 0;
        long ans_max, ans;
        ans_max = ans = 1;
        int left_n, right_n, parent_n;
        for (int i = 0; i < n; i++){
            if (tree_node[i].second.first != -2)
                left_n = tree_node[tree_node[i].second.first].first;
            else 
                left_n = 0;
            if (tree_node[i].second.second != -2)
                right_n = tree_node[tree_node[i].second.second].first;
            else 
                right_n = 0;
            parent_n = n - 1 - right_n - left_n;
            ans = 1;
            if (left_n != 0)
                ans = ans * left_n;
            if (right_n != 0)
                ans = ans * right_n;
            if (parent_n != 0)
                ans = ans * parent_n;
            if (ans > ans_max){
                ans_max = ans;
                max_num = 1;
            }
            else if (ans < ans_max)
                continue;
            else // ans == ans_max
                max_num++;
        }
        return max_num;
    }
};
