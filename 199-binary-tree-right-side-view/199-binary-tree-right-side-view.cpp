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
    vector<int> res;
    queue<TreeNode*> q;
    
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        TreeNode* temp;
        
        while (!q.empty()) {
            temp = q.front();
            q.pop();
            if (temp == nullptr) {
                if (q.empty())
                    break;
                else
                    q.push(nullptr);
            }   
            else {
                if (temp -> left)
                    q.push(temp -> left);
                if (temp -> right)
                    q.push(temp -> right);
                if (q.front() == nullptr)
                    res.push_back(temp -> val);
            }
        }
        return res;
    }
};