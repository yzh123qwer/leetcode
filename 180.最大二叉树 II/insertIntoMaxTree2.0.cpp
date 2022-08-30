class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (val > root->val){
            TreeNode* new_node = new(TreeNode);
            new_node->val = val;
            new_node->left = root;
            new_node->right = nullptr;
            return new_node;
        }
        else {
            if (root->right != nullptr){
                root->right = insertIntoMaxTree(root->right, val);
            }
            else {
                root->right = new(TreeNode);
                root->right->val = val;
                root->right->left = nullptr;
                root->right->right = nullptr;
            }
            return root;
        }
    }
};
