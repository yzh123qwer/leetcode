/*
998. 最大二叉树 II
最大树 定义：一棵树，并满足：其中每个节点的值都大于其子树中的任何其他值。

给你最大树的根节点 root 和一个整数 val 。

就像 之前的问题 那样，给定的树是利用 Construct(a) 例程从列表 a（root = Construct(a)）递归地构建的：

如果 a 为空，返回 null 。
否则，令 a[i] 作为 a 的最大元素。创建一个值为 a[i] 的根节点 root 。
root 的左子树将被构建为 Construct([a[0], a[1], ..., a[i - 1]]) 。
root 的右子树将被构建为 Construct([a[i + 1], a[i + 2], ..., a[a.length - 1]]) 。
返回 root 。
请注意，题目没有直接给出 a ，只是给出一个根节点 root = Construct(a) 。

假设 b 是 a 的副本，并在末尾附加值 val。题目数据保证 b 中的值互不相同。

返回 Construct(b) 。

示例 1：
输入：root = [4,1,3,null,null,2], val = 5
输出：[5,4,null,1,3,null,null,2]
解释：a = [1,4,2,3], b = [1,4,2,3,5]
示例 2：
输入：root = [5,2,4,null,1], val = 3
输出：[5,2,4,null,1,null,3]
解释：a = [2,1,5,4], b = [2,1,5,4,3]
示例 3：
输入：root = [5,2,3,null,1], val = 4
输出：[5,2,4,null,1,3]
解释：a = [2,1,5,3], b = [2,1,5,3,4]
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
    void Tree_to_a(vector<int>& Tree_a, TreeNode* T){
        if (T->left != nullptr)
            Tree_to_a(Tree_a, T->left);
        Tree_a.push_back(T->val);
        if (T->right != nullptr)
            Tree_to_a(Tree_a, T->right);
        return;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return main_fun(nums, 0, nums.size() - 1);
    }
    TreeNode* main_fun(vector<int>& nums, int i, int j){
        if (i == j){
            TreeNode* temp = new(TreeNode);
            temp->val = nums[i];
            temp->right = nullptr;
            temp->left = nullptr;
            return temp;
        }
        int max_i = i;
        for (int ii = i + 1; ii <= j; ii++){
            if (nums[ii] > nums[max_i])
                max_i = ii;
        }
        TreeNode* temp = new(TreeNode);
        temp->val = nums[max_i];
        if (max_i == j)
            temp->right = nullptr;
        else 
            temp->right = main_fun(nums, max_i + 1, j);
        if (max_i == i)
            temp->left = nullptr;
        else 
            temp->left = main_fun(nums, i, max_i - 1);
        return temp;
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> Tree_a;
        Tree_to_a(Tree_a, root);
        Tree_a.push_back(val);
        return constructMaximumBinaryTree(Tree_a);
    }
};
