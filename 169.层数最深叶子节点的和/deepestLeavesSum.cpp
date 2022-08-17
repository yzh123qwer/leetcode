/*
1302. 层数最深叶子节点的和
给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。

示例 1：



输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
示例 2：

输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
输出：19
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> Q;
        if (root == nullptr)
            return 0;
        Q.push(root);
        int Q_size;
        int sum = 0;
        while (!Q.empty()){
            sum = 0;
            Q_size = Q.size();
            for (int i = 0; i < Q_size; i++){
                sum += Q.front()->val;
                if (Q.front()->right != nullptr)
                    Q.push(Q.front()->right);
                if (Q.front()->left != nullptr)
                    Q.push(Q.front()->left);
                Q.pop();
            }
        }
        return sum;
    }
};
