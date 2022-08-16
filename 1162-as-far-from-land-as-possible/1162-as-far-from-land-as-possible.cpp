class Solution {
public:
    int n;
    queue<tuple<int, int, int>> q;
    
    void bfs(vector<vector<int>>& grid) {
        int ti, tj, d;
        while (!q.empty()) {
            ti = get<0>(q.front());
            tj = get<1>(q.front());
            d = get<2>(q.front());
            q.pop();
            if ((0 <= ti-1) && !grid[ti-1][tj]) {
                grid[ti-1][tj] = d+1;
                q.push({ti-1, tj, d+1});
            }
            if ((0 <= tj-1) && !grid[ti][tj-1]) {
                grid[ti][tj-1] = d+1;
                q.push({ti, tj-1, d+1});
            }
            if ((ti+1 < n) && !grid[ti+1][tj]) {
                grid[ti+1][tj] = d+1;
                q.push({ti+1, tj, d+1});
            }
            if ((tj+1 < n) && !grid[ti][tj+1]) {
                grid[ti][tj+1] = d+1;
                q.push({ti, tj+1, d+1});
            }
        }
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j])
                    q.push({i, j, 1});
        bfs(grid);
        int max_dist = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                max_dist = max(max_dist, grid[i][j]);
        return ((max_dist != 1) ? max_dist-1 : -1);
    }
};