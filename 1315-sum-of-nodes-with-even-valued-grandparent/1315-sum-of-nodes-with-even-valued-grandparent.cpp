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
    int sum_nodes;
public:
    void calc_sum_nodes(TreeNode* root, int parent, int grandparent) {
        if (root) {
            if (!(grandparent % 2))
                sum_nodes += (root -> val);
            calc_sum_nodes(root -> left, root -> val, parent);
            calc_sum_nodes(root -> right, root -> val, parent);
        }
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        sum_nodes = 0;
        calc_sum_nodes(root, -1, -1);
        return sum_nodes;
    }
};