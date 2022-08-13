class Solution {
public:
    int m, n, flag;
    
    int check_closed(vector<vector<int>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 2;
        while (!q.empty()) {
            int ti = q.front().first, tj = q.front().second;
            q.pop();
            if (ti == 0 || tj == 0 || ti == m-1 || tj == n-1)
                flag = 0;
            if ((0 <= ti-1) && !grid[ti-1][tj]) {
                grid[ti-1][tj] = 2;
                q.push({ti-1, tj});
            }
            if ((0 <= tj-1) && !grid[ti][tj-1]) {
                grid[ti][tj-1] = 2;
                q.push({ti, tj-1});
            }
            if ((ti+1 < m) && !grid[ti+1][tj]) {
                grid[ti+1][tj] = 2;
                q.push({ti+1, tj});
            }
            if ((tj+1 < n) && !grid[ti][tj+1]) {
                grid[ti][tj+1] = 2;
                q.push({ti, tj+1});
            }
        }
        return 0;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    flag = 1;
                    check_closed(grid, i, j);
                    if (flag) count++;
                }
            }
        }
        return count;
    }
};