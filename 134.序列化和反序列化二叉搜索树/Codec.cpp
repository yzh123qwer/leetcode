/*
449. 序列化和反序列化二叉搜索树
序列化是将数据结构或对象转换为一系列位的过程，以便它可以存储在文件或内存缓冲区中，或通过网络连接链路传输，以便稍后在同一个或另一个计算机环境中重建。

设计一个算法来序列化和反序列化 二叉搜索树 。 对序列化/反序列化算法的工作方式没有限制。 您只需确保二叉搜索树可以序列化为字符串，并且可以将该字符串反序列化为最初的二叉搜索树。

编码的字符串应尽可能紧凑。

 

示例 1：

输入：root = [2,1,3]
输出：[2,1,3]
示例 2：

输入：root = []
输出：[]
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
class Codec {
    string int_str(int a){
        string temp;
        while (a != 0){
            temp.push_back(a % 10 + '0');
            a /= 10;
        }
        string ans;
        for (int i = temp.size() - 1; i > -1; i--)
            ans.push_back(temp[i]);
        return ans;
    }
    void Insert(TreeNode* &root, int s){
        if (root == nullptr){
            root = new(TreeNode);
            root->val = s;
            root->left = nullptr;
            root->right = nullptr;
            return;
        }
        if (s > root->val){
            Insert(root->right, s);
            return;
        }
        else{
            Insert(root->left, s);
            return; // 注意没有节点重复的情况
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int q_size;
        string ans;
        // TreeNode* q_front;
        while(!q.empty()){
            q_size = q.size();
            for (int i = 0; i < q_size; i++){
                if (q.front() == nullptr){
                    q.pop();
                    continue;
                }
                ans += int_str(q.front()->val);
                ans.push_back('!'); // 每个数字之间使用!分隔。
                q.push(q.front()->right);
                q.push(q.front()->left);
                q.pop();
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        int temp;
        for (int i = 0; i < data.size(); i++){
            temp = 0;
            while (data[i] != '!'){
                temp = temp * 10 + data[i] - '0';
                i++;
            }
            Insert(root, temp);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
