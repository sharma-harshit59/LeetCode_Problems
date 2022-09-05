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
    vector<tuple<int, int, int>> arr;
    
    void insert_nodes(TreeNode* root, int row, int col) {
        if (root) {
            arr.push_back({col, row, (root -> val)});
            insert_nodes(root -> left, row + 1, col - 1);
            insert_nodes(root -> right, row + 1, col + 1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        insert_nodes(root, 0, 0);
        sort(arr.begin(), arr.end());
        vector<vector<int>> res;
        vector<int> temp{get<2>(arr[0])};
        for (int i = 1; i < arr.size(); i++) {
            if (get<0>(arr[i]) == get<0>(arr[i-1]))
                temp.push_back(get<2>(arr[i]));
            else {
                res.push_back(temp);
                temp = {get<2>(arr[i])};
            }
        }
        res.push_back(temp);
        return res;
    }
};