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
        queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(nullptr);
        vector<double> avg_sum;
        double sum = 0, tot = 0;
        TreeNode* n;
        
        while (!nodes.empty()) {
            n = nodes.front();
            nodes.pop();
            if (n == nullptr) {
                if (nodes.empty())
                    break;
                nodes.push(nullptr);
                avg_sum.push_back(sum / tot);
                sum = 0;
                tot = 0;
            }
            else {
                sum += n -> val;
                tot++;
                if (n -> left)
                    nodes.push(n -> left);
                if (n -> right)
                    nodes.push(n -> right);
            }
        }
        avg_sum.push_back(sum / tot);
        return avg_sum;
    }
};