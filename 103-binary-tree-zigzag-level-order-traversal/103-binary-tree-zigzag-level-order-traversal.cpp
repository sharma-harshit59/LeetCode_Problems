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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        vector<int> temp_vec;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        TreeNode* temp_node;
        int flag = 1;
        
        while (!q.empty()) {
            temp_node = q.front();
            q.pop();
            if (temp_node == nullptr) {
                flag = !flag;
                if (flag)
                    reverse(temp_vec.begin(), temp_vec.end());
                res.push_back(temp_vec);
                if (q.empty())
                    break;
                else {
                    q.push(nullptr);
                    temp_vec = {};
                }
            }
            else {
                temp_vec.push_back(temp_node -> val);
                if (temp_node -> left)
                    q.push(temp_node -> left);
                if (temp_node -> right)
                    q.push(temp_node -> right);
            }
        }
        return res;
    }
};