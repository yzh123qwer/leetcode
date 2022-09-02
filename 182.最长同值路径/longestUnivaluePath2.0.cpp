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
