/*
653. 两数之和 IV - 输入 BST
给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

 

示例 1：


输入: root = [5,3,6,2,4,null,7], k = 9
输出: true
示例 2：


输入: root = [5,3,6,2,4,null,7], k = 28
输出: false
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
    unordered_map<int, int> hash;
    bool findTarget(TreeNode* root, int k) {
        hash_insert(root);
        for (auto i : hash){
            if (hash.find(k - i.first) == hash.end())
                continue;
            else {
                if ((k - i.first) == i.first){
                    if (hash.find(i.first)->second >= 2)
                        return true;
                    else
                        continue;
                }
                else 
                    return true;
            }
        }
        return false;
    }
    void hash_insert(TreeNode *root){
        if (root == nullptr)
            return;
        else {
            if (hash.find(root->val) == hash.end()){
                hash.insert(make_pair(root->val, 1));
            }
            else 
                hash.find(root->val)->second += 1;
            hash_insert(root->left);
            hash_insert(root->right);
            return;
        }
    }
};
