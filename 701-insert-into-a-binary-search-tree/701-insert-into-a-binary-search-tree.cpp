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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if (!root)
            return newNode;
        TreeNode* temp = root;
        while ((temp -> val) != val) {
            if ((temp -> val) < val) {
                if (temp -> right)
                    temp = (temp -> right);
                else {
                    (temp -> right) = newNode;
                    return root;
                }
            }
            else {
                if (temp -> left)
                    temp = (temp -> left);
                else {
                    (temp -> left) = newNode;
                    return root;
                }
            }
        }
        return nullptr;
    }
};