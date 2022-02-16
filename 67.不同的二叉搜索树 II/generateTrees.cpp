/*
95. 不同的二叉搜索树 II
给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。

 

示例 1：


输入：n = 3
输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
示例 2：

输入：n = 1
输出：[[1]]
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        TreeNode* root = nullptr;
        for (int i = 1; i <= n; i++){
            root = (TreeNode*)malloc(sizeof(TreeNode));
            root->val = i;
            root->left = nullptr;
            root->right = nullptr;
            makeTrees(root, root, make_pair(1, i - 1), make_pair(i + 1, n), ans);
        }
        return ans;
    }
    void makeTrees(TreeNode *root, TreeNode* T, pair<int, int> left, pair<int, int> right, vector<TreeNode*>& ans){
        if (left.first > left.second)
            T->left = nullptr;
        else if (left.first == left.second){
            T->left = (TreeNode*)malloc(sizeof(TreeNode));
            T->left->val = left.first;
            T->left->right = nullptr;
            T->left->left = nullptr;
        }
        else {//left.first < left.second
            for (int i = left.first; i <= left.second; i++){
                T->left = (TreeNode*)malloc(sizeof(TreeNode));
                T->left->val = i;
                makeTrees(root, T->left, make_pair(left.first, i - 1), make_pair(i + 1, left.second), ans);
            }
        }
        if (right.first > right.second){
            T->right = nullptr;
            ans.push_back(root);
        }
        else if (right.first == right.second){
            T->right = (TreeNode*)malloc(sizeof(TreeNode));
            T->right->val = right.first;
            T->right->right = nullptr;
            T->right->left = nullptr;
            ans.push_back(root);
        }
        else {//right.first < right.second
            for (int i = right.first; i <= right.second; i++){
                T->right = (TreeNode*)malloc(sizeof(TreeNode));
                T->right->val = i;
                makeTrees(root, T->right, make_pair(right.first, i - 1), make_pair(i + 1, right.second), ans);
            }            
        }
        return;
    }
};
