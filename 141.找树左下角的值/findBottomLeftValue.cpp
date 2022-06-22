/*
513. 找树左下角的值
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。

 

示例 1:



输入: root = [2,1,3]
输出: 1
示例 2:



输入: [1,2,3,4,null,5,6,null,null,7]
输出: 7
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int ans;
        int Q_size = 1;
        while (!Q.empty()) {
            ans = Q.front()->val;
            Q_size = Q.size();
            for (int i = 0; i < Q_size; i++) {
                if (Q.front()->left != nullptr)
                    Q.push(Q.front()->left);
                if (Q.front()->right != nullptr)
                    Q.push(Q.front()->right);
                Q.pop();
            }
        }
        return ans;
    }
};
