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
    int sum;
    
    void soll(TreeNode* root, int is_left) {
        if (!(root -> left) && !(root -> right) && is_left)
            sum += (root -> val);
        else {
            if (root -> left)
                soll((root -> left), 1);
            if (root -> right)
                soll((root -> right), 0);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        soll(root, 0);
        return sum;
    }
};