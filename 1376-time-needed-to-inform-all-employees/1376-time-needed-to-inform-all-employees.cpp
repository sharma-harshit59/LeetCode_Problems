class Solution {
public:
    int n;
    
    int dfs(int node, vector<vector<int>>& adj, vector<int>& time) {
        int t = 0;
        for (auto i: adj[node])
            t = max(t, dfs(i, adj, time));
        return t + time[node];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        n = manager.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        return dfs(headID, adj, informTime);
    }
};