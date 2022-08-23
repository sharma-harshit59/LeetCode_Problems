class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int i: graph[node])
            if (!visited[i])
                dfs(i, graph, visited);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(0, rooms, visited);
        for (int i = 0; i < visited.size(); i++)
            if (!visited[i])
                return false;
        return true;
    }
};