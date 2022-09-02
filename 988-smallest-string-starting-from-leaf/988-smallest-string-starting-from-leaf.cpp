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
    vector<string> smallest;
    
    void calc_string(TreeNode* root, string str) {
        str = char((root -> val) + 'a') + str;
        if (!((root -> left) || (root -> right)))
            smallest.push_back(str);
        else {
            if (root -> left)
                calc_string(root -> left, str);
            if (root -> right)
                calc_string(root -> right, str);
        }
    }
    
    string smallestFromLeaf(TreeNode* root) {
        calc_string(root, "");
        string res = smallest[0];
        for (string i: smallest)
            if (i < res)
                res = i;
        return res;
    }
};