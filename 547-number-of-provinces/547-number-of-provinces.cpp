class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int i = 1; i <= graph.size(); i++)
            if (!visited[i] && graph[node-1][i-1])
                dfs(i, graph, visited);
    }
    
    int findCircleNum(vector<vector<int>>& isConn) {
        int n = isConn.size(), count = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, isConn, visited);
                count++;
            }
        }
        return count;
    }
};