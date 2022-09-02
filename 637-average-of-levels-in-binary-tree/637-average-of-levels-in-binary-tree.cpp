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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<double> res;
        double sum = 0, n = 0;
        while (true) {
            TreeNode* temp = q.front();
            q.pop();
            if (!temp) {
                if (q.empty())
                    break;
                else {
                    res.push_back(sum / n);
                    sum = 0;
                    n = 0;
                    q.push(nullptr);
                }
            }
            else {
                sum += (temp -> val);
                n++;
                if (temp -> left)
                    q.push(temp -> left);
                if (temp -> right)
                    q.push(temp -> right);
            }
        }
        res.push_back(sum / n);
        return res;
    }
};