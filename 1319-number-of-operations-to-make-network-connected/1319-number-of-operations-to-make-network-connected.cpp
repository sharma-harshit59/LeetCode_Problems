class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, int& count_edges, vector<bool>& nodes) {
        nodes[node] = true;
        for (int i: graph[node]) {
            if (!nodes[i]) {
                count_edges++;
                dfs(i, graph, count_edges, nodes);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        vector<vector<int>> adj(n);
        vector<bool> visited_nodes(n, false);
        for (int i = 0; i < conn.size(); i++) {
            adj[conn[i][0]].push_back(conn[i][1]);
            adj[conn[i][1]].push_back(conn[i][0]);
        }
        int count = 0, count_edges = 0;
        for (int i = 0; i < n; i++) {
            if (!visited_nodes[i]) {
                dfs(i, adj, count_edges, visited_nodes);
                count++;
            }
        }
        return ((conn.size() - count_edges) >= count-1) ? (count-1) : -1;
    }
};