/*
2049. 统计最高分的节点数目
给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，节点编号为 0 到 n - 1 。同时给你一个下标从 0 开始的整数数组 parents 表示这棵树，其中 parents[i] 是节点 i 的父节点。由于节点 0 是根，所以 parents[0] == -1 。

一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数 。求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除 ，剩余部分是若干个 非空 子树，这个节点的 分数 为所有这些子树 大小的乘积 。

请你返回有 最高得分 节点的 数目 。

 

示例 1:

example-1

输入：parents = [-1,2,0,2,0]
输出：3
解释：
- 节点 0 的分数为：3 * 1 = 3
- 节点 1 的分数为：4 = 4
- 节点 2 的分数为：1 * 1 * 2 = 2
- 节点 3 的分数为：4 = 4
- 节点 4 的分数为：4 = 4
最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
示例 2：

example-2

输入：parents = [-1,2,0]
输出：2
解释：
- 节点 0 的分数为：2 = 2
- 节点 1 的分数为：2 = 2
- 节点 2 的分数为：1 * 1 = 1
最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
*/
class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size(); // n为二叉树的节点个数
        unordered_map<int, pair<int, int>> tree_node;
        for (int i = 0; i < parents.size(); i++) {
            if (tree_node.find(parents[i]) == tree_node.end()) {
                tree_node.insert(make_pair(parents[i], make_pair(i, -2)));
            }
            else {
                tree_node.find(parents[i])->second.second = i;
            }
        }
        int n_left_tree, n_right_tree, n_parents_tree;
        long max_n3 = 0, max_n = 0; // max_n3存放3个数的积最大值，max_n存放最大积出现次数
        long temp_ans;
        for (int i = 0; i < parents.size(); i++) {
            if (tree_node.find(i) == tree_node.end()) {
                n_parents_tree = n - 1;
                if (n_parents_tree > max_n3) {
                    max_n3 = n_parents_tree;
                    max_n = 1;
                    continue;
                }
                else if (n_parents_tree < max_n3)
                    continue;
                else { // n_parents_tree == max_n3
                    max_n++;
                    continue;
                }
            }
            else {
                n_left_tree = n_right_tree = 0;
                find_tree_n(tree_node.find(i)->second.first, tree_node, n_left_tree);
                find_tree_n(tree_node.find(i)->second.second, tree_node, n_right_tree);
                n_parents_tree = n - 1 - n_right_tree - n_left_tree;
                temp_ans = 1;
                if (n_left_tree != 0)
                    temp_ans = temp_ans * n_left_tree;
                if (n_right_tree != 0)
                    temp_ans = temp_ans * n_right_tree;
                if (n_parents_tree != 0)
                    temp_ans = temp_ans * n_parents_tree;
                if (temp_ans > max_n3) {
                    max_n3 = temp_ans;
                    max_n = 1;
                    continue;
                }
                else if (temp_ans < max_n3)
                    continue;
                else {
                    max_n++;
                    continue;
                }
            }
        }
        return max_n;
    }
    void find_tree_n(int a, unordered_map<int, pair<int, int>>& A, int& n) {
        if (a != -2) {
            n++;
            if (A.find(a) != A.end()){
                find_tree_n(A.find(a)->second.first, A, n);
                find_tree_n(A.find(a)->second.second, A, n);
            }
        }
        return;
    }
};
