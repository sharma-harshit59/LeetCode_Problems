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
    unsigned int sum = 0;
    
    void calc_num(TreeNode* root, int n) {
        if (!((root -> left) || (root -> right)))
            sum += ((n * 10) + (root -> val));
        else {
            if (root -> left)
                calc_num(root -> left, ((n * 10) + (root -> val)));
            if (root -> right)
                calc_num(root -> right, ((n * 10) + (root -> val)));
        }
    }
    
    int sumNumbers(TreeNode* root) {
        calc_num(root, 0);
        return sum;
    }
};