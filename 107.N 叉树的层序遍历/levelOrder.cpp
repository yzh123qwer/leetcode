/*
429. N 叉树的层序遍历
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

示例 1：

输入：root = [1,null,3,2,4,null,5,6]
输出：[[1],[3,2,4],[5,6]]
示例 2：

输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        if (root == nullptr)
            return ans;
        queue<Node*> q_node;
        q_node.push(root);
        int count;
        while (q_node.empty() == false){
            for (count = q_node.size(), temp.clear(); count > 0; count--){
                temp.push_back(q_node.front()->val);
                if (q_node.front()->children.size() != 0){
                    for (auto i : q_node.front()->children)
                        q_node.push(i);
                }
                q_node.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
