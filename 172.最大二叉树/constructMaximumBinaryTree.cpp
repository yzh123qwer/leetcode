/*
654. 最大二叉树
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:

创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。

示例 1：

输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。
示例 2：


输入：nums = [3,2,1]
输出：[3,null,2,null,1]
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return main_fun(nums, 0, nums.size() - 1);
    }
};
