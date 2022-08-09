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
    vector<int> elements;
    
    void get_elements(TreeNode* root) {
        if (root) {
            elements.push_back(root -> val);
            get_elements(root -> left);
            get_elements(root -> right);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        elements = {};
        get_elements(root1);
        get_elements(root2);
        sort(elements.begin(), elements.end());
        return elements;
    }
};