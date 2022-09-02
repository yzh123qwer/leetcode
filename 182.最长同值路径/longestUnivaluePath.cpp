/*
687. 最长同值路径
给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。

两个节点之间的路径长度 由它们之间的边数表示。

示例 1:

输入：root = [5,4,5,1,1,5]
输出：2
示例 2:

输入：root = [1,4,5,4,4,5]
输出：2
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
    int res;
    int main_fun(TreeNode* T){
        if (T == nullptr)
            return 0;
        int right = main_fun(T->right);
        int left = main_fun(T->left);
        int right_ = 0, left_ = 0;
        if (T->right != nullptr && T->val == T->right->val)
            right_ = right + 1;
        if (T->left != nullptr && T->val == T->left->val)
            left_ = left + 1;
        int ans = left_ + right_;
        res = max(res, ans);
        return max(left_, right_);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        main_fun(root);
        return res;
    }
};
