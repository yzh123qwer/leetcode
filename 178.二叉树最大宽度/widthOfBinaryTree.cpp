/*
662. 二叉树最大宽度
给你一棵二叉树的根节点 root ，返回树的 最大宽度 。

树的 最大宽度 是所有层中最大的 宽度 。

每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 null 节点，这些 null 节点也计入长度。

题目数据保证答案将会在  32 位 带符号整数范围内。

示例 1：

输入：root = [1,3,2,5,3,null,9]
输出：4
解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
示例 2：

输入：root = [1,3,2,5,null,null,9,6,null,7]
输出：7
解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
示例 3：

输入：root = [1,3,2,5]
输出：2
解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<unsigned long, TreeNode*>> Q;
        int Q_size = 0;
        Q.push(make_pair(1, root));
        int ret = 0;
        int temp = 0;
        unsigned long min = 0;
        while (!Q.empty()){
            Q_size = Q.size();
            min = Q.front().first;
            for (int i = 0; i < Q_size - 1; i++){
                if (Q.front().second->left != nullptr)
                    Q.push(make_pair(Q.front().first * 2, Q.front().second->left));
                if (Q.front().second->right != nullptr)
                    Q.push(make_pair(Q.front().first * 2 + 1, Q.front().second->right));
                Q.pop();
            }
            temp = Q.front().first - min + 1;
            if (Q.front().second->left != nullptr)
                Q.push(make_pair(Q.front().first * 2, Q.front().second->left));
            if (Q.front().second->right != nullptr)
                Q.push(make_pair(Q.front().first * 2 + 1, Q.front().second->right));
            Q.pop();
            if (temp > ret)
                ret = temp;
        }
        return ret;
    }
};
