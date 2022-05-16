/*
面试题 04.06. 后继者
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1

输出: null
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* Search(TreeNode* root, int n, TreeNode* &F_right){
        if (root == nullptr)
            return nullptr;
        if (n == root->val)
            return root;
        else if (n > root->val){
            
            return Search(root->right, n, F_right);
        }
        else { // n < root->val
            F_right = root;
            return Search(root->left, n, F_right);
        }
    }
    TreeNode* Search(TreeNode* root){ // 返回最小值
        if (root == nullptr)
            return nullptr;
        if (root->left != nullptr)
            return Search(root->left);
        else
            return root;
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p == nullptr)
            return nullptr;
        int p_val = p->val;
        TreeNode* F_right = nullptr;
        TreeNode* ans = Search(root, p_val, F_right);
        TreeNode* ans_right_min = Search(ans->right);
        if (ans == nullptr)
            return nullptr;
        if (F_right == nullptr)
            return ans_right_min;
        if (ans_right_min == nullptr)
            return F_right;
        if (ans_right_min->val < F_right->val)
            return ans_right_min;
        else 
            return F_right;
    }
};
