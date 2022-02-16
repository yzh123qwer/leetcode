/*
94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        search_node(root, ans);
        return ans;
    }
    void search_node(TreeNode* T, vector<int>& ans){
        if (T->left == nullptr);
        else 
            search_node(T->left, ans);
        ans.push_back(T->val);
        if (T->right == nullptr);
        else 
            search_node(T->right, ans);
        return;
    }
};
