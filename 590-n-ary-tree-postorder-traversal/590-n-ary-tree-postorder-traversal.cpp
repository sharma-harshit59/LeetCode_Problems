/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    
    void post_traverse(Node* root) {
        if (root) {
            for (auto itr: (root -> children))
                postorder(itr);
            res.push_back(root -> val);
        }
    }
    
    vector<int> postorder(Node* root) {
        post_traverse(root);
        return res;
    }
};