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
    void inorder(TreeNode* root, vector<int> &V) {
        if (root) {
            inorder(root -> left, V);
            V.push_back(root -> val);
            inorder(root -> right, V);
        }
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> inorder_arr;
        inorder(root, inorder_arr);
        for (int i = 1; i < inorder_arr.size(); i++)
            if (inorder_arr[i] <= inorder_arr[i-1])
                return false;
        return true;
    }
};