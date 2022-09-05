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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        vector<int> temp;
        queue<Node*> q;
        if (root) {
            q.push(root);
            q.push(nullptr);
        }
        while (!q.empty()) {
            Node *t = q.front();
            q.pop();
            if (t == nullptr) {
                res.push_back(temp);
                if (q.empty())
                    break;
                q.push(nullptr);
                temp = {};
            }
            else {
                temp.push_back(t -> val);
                for (auto itr: t -> children)
                    q.push(itr);
            }
        }
        return res;
    }
};