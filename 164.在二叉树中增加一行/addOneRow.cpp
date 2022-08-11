/*
623. 在二叉树中增加一行
给定一个二叉树的根 root 和两个整数 val 和 depth ，在给定的深度 depth 处添加一个值为 val 的节点行。

注意，根节点 root 位于深度 1 。

加法规则如下:

给定整数 depth，对于深度为 depth - 1 的每个非空树节点 cur ，创建两个值为 val 的树节点作为 cur 的左子树根和右子树根。
cur 原来的左子树应该是新的左子树根的左子树。
cur 原来的右子树应该是新的右子树根的右子树。
如果 depth == 1 意味着 depth - 1 根本没有深度，那么创建一个树节点，值 val 作为整个原始树的新根，而原始树就是新根的左子树。
 

示例 1:



输入: root = [4,2,6,3,1,5], val = 1, depth = 2
输出: [4,1,1,2,null,null,6,3,1,5]
示例 2:



输入: root = [4,2,null,3,1], val = 1, depth = 3
输出:  [4,2,null,1,1,3,null,null,1]
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* new_root = new(TreeNode);
            new_root->val = val;
            new_root->left = root;
            new_root->right = nullptr;
            return new_root;
        }
        queue<TreeNode*> q_depth_up;
        int q_size;
        q_depth_up.push(root);
        for (int i = 1; i < depth - 1; i++) {
            q_size = q_depth_up.size();
            for (int ii = 0; ii < q_size; ii++) {
                if (q_depth_up.front()->left != nullptr)
                    q_depth_up.push(q_depth_up.front()->left);
                if (q_depth_up.front()->right != nullptr)
                    q_depth_up.push(q_depth_up.front()->right);
                q_depth_up.pop();
            }
        }
        cout << q_depth_up.front()->val;

        TreeNode* temp = nullptr;
        TreeNode* temp_l = nullptr;
        TreeNode* temp_r = nullptr;
        while (!q_depth_up.empty()){
            temp = q_depth_up.front();
            q_depth_up.pop();
            if (temp->left != nullptr){
                temp_l = new(TreeNode);
                temp_l->val = val;
                temp_l->left = temp->left;
                temp_l->right = nullptr;
                temp->left = temp_l;
            }
            else {
                temp_l = new(TreeNode);
                temp_l->val = val;
                temp_l->left = nullptr;
                temp_l->right = nullptr;
                temp->left = temp_l;
            }
            if (temp->right != nullptr){
                temp_r = new(TreeNode);
                temp_r->val = val;
                temp_r->left = nullptr;
                temp_r->right = temp->right;
                temp->right = temp_r;
            }
            else {
                temp_r = new(TreeNode);
                temp_r->val = val;
                temp_r->left = nullptr;
                temp_r->right = nullptr;
                temp->right = temp_r;
            }
        }
        return root;
    }
};
