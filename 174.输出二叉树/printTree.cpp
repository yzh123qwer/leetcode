/*
655. 输出二叉树
给你一棵二叉树的根节点 root ，请你构造一个下标从 0 开始、大小为 m x n 的字符串矩阵 res ，用以表示树的 格式化布局 。构造此格式化布局矩阵需要遵循以下规则：

树的 高度 为 height ，矩阵的行数 m 应该等于 height + 1 。
矩阵的列数 n 应该等于 2height+1 - 1 。
根节点 需要放置在 顶行 的 正中间 ，对应位置为 res[0][(n-1)/2] 。
对于放置在矩阵中的每个节点，设对应位置为 res[r][c] ，将其左子节点放置在 res[r+1][c-2height-r-1] ，右子节点放置在 res[r+1][c+2height-r-1] 。
继续这一过程，直到树中的所有节点都妥善放置。
任意空单元格都应该包含空字符串 "" 。
返回构造得到的矩阵 res 。

示例 1：

输入：root = [1,2]
输出：
[["","1",""],
 ["2","",""]]
示例 2：


输入：root = [1,2,3,null,4]
输出：
[["","","","1","","",""],
 ["","2","","","","3",""],
 ["","","4","","","",""]]
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
    void fun(vector<vector<string>>& ans, int r, int c, TreeNode* T, int height){
        string temp = to_string(T->val);
        ans[r][c] = temp;
        if (T->left != nullptr){
            fun(ans, r + 1, c - pow(2, height - r - 1), T->left, height);
        }
        if (T->right != nullptr){
            fun(ans, r + 1, c + pow(2, height - r - 1), T->right, height);
        }
        return;
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int Q_size;
        int height = -1; // 树的高度从0开始。
        while (!Q.empty()){
            Q_size = Q.size();
            height++;
            for (int i = 0; i < Q_size; i++){
                if (Q.front()->left != nullptr)
                    Q.push(Q.front()->left);
                if (Q.front()->right != nullptr)
                    Q.push(Q.front()->right);
                Q.pop();
            }
        }
        int m = height + 1; 
        int n = pow(2, height + 1) - 1;
        vector<vector<string>> ans(m, vector<string>(n, ""));
        int r = 0;
        int c = (n - 1) / 2;
        fun(ans, r, c, root, height);
        return ans;
    }
};
 
