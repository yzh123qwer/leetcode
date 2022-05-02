/*
1305. 两棵二叉搜索树中的所有元素
给你 root1 和 root2 这两棵二叉搜索树。请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。.

 

示例 1：



输入：root1 = [2,1,4], root2 = [1,0,3]
输出：[0,1,1,2,3,4]
示例 2：



输入：root1 = [1,null,8], root2 = [8,1]
输出：[1,1,8,8]
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
    vector<int> v_root1;
    vector<int> v_root2;
    void fun1(TreeNode *root){
        if (root == nullptr)
            return;
        fun1(root->left);
        v_root1.push_back(root->val);
        fun1(root->right);
        return;
    }
    void fun2(TreeNode *root){
        if (root == nullptr)
            return;
        fun2(root->left);
        v_root2.push_back(root->val);
        fun2(root->right);
        return;
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        fun1(root1);
        fun2(root2);
        vector<int> ans;
        int i = 0, j = 0;
        while(ans.size() != v_root1.size() + v_root2.size()){
            if (i == v_root1.size()){
                while(j != v_root2.size())
                    ans.push_back(v_root2[j++]);
                break;
            }
            else if (j == v_root2.size()){
                while(i != v_root1.size())
                    ans.push_back(v_root1[i++]);
                break;
            }
            if (v_root1[i] > v_root2[j])
                ans.push_back(v_root2[j++]);
            else 
                ans.push_back(v_root1[i++]);
        }
        return ans;
    }
};
