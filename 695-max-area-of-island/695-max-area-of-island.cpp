class Solution {
public:
    int m, n;
    int calc_area(vector<vector<int>>& grid, int i, int j) {
        int area = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        while (!q.empty()) {
            int ti = q.front().first, tj = q.front().second;
            q.pop();
            area++;
            if ((0 <= ti-1) && grid[ti-1][tj]) {
                q.push({ti-1, tj});
                grid[ti-1][tj] = 0;
            }
            if ((ti+1 < m) && grid[ti+1][tj]) {
                q.push({ti+1, tj});
                grid[ti+1][tj] = 0;
            }
            if ((0 <= tj-1) && grid[ti][tj-1]) {
                q.push({ti, tj-1});
                grid[ti][tj-1] = 0;
            }
            if ((tj+1 < n) && grid[ti][tj+1]) {
                q.push({ti, tj+1});
                grid[ti][tj+1] = 0;
            }
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int max_area = 0, temp_area;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    temp_area = calc_area(grid, i, j);
                    max_area = max(max_area, temp_area);
                }
            }
        }
        return max_area;
    }
};