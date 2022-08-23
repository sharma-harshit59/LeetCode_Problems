class Solution {
public:
    vector<vector<int>> res;
    void dfs(int node, vector<vector<int>>& graph, unordered_set<int> visited, vector<int> path) {
        path.push_back(node);
        visited.insert(node);
        if (node == graph.size()-1) {
            res.push_back(path);
            return;
        }
        for (int i: graph[node])
            if (!visited.count(i))
                dfs(i, graph, visited, path);
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph, {}, {});
        return res;
    }
};