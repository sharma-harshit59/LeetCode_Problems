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
    TreeNode* construct(vector<int> nums) {
        auto M = max_element(nums.begin(), nums.end());
        TreeNode* temp = new TreeNode(*M);
        vector<int> left(nums.begin(), M), right(M+1, nums.end());
        if (left.size())
            (temp -> left) = construct(left);
        if (right.size())
            (temp -> right) = construct(right);
        return temp;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root;
        root = construct(nums);
        return root;
    }
};