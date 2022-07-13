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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        TreeNode* temp;
        vector<int> t;
        vector<vector<int>> res;
        
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp == nullptr) {
                res.push_back(t);
                if (q.empty())
                    break;
                else {
                    q.push(nullptr);
                    t = {};
                }
            }
            else {
                t.push_back(temp -> val);
                if (temp -> left)
                    q.push(temp -> left);
                if (temp -> right)
                    q.push(temp -> right);
            }
        }
        return res;
    }
};