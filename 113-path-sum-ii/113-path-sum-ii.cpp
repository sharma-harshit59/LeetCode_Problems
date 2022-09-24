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
    vector<vector<int>> res;
    
    void traverse_sum(TreeNode* root, int k, vector<int> arr, int sum_arr) {
        arr.push_back(root -> val);
        sum_arr += (root -> val);
        if ((root -> left) || (root -> right)) {
            if (root -> left) traverse_sum((root -> left), k, arr, sum_arr);
            if (root -> right) traverse_sum((root -> right), k, arr, sum_arr);
        }
        else {
            if (sum_arr == k)
                res.push_back(arr);
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root)
            traverse_sum(root, targetSum, {}, 0);
        return res;
    }
};