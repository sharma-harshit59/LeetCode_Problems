class Solution {
public:
    int m, n, flag;
    
    void check_closed(vector<vector<int>>& grid, int i, int j, int& count) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        while (!q.empty()) {
            int ti = q.front().first, tj = q.front().second;
            count++;
            q.pop();
            if (ti == 0 || tj == 0 || ti == m-1 || tj == n-1)
                flag = 0;
            if ((0 <= ti-1) && grid[ti-1][tj]) {
                grid[ti-1][tj] = 0;
                q.push({ti-1, tj});
            }
            if ((0 <= tj-1) && grid[ti][tj-1]) {
                grid[ti][tj-1] = 0;
                q.push({ti, tj-1});
            }
            if ((ti+1 < m) && grid[ti+1][tj]) {
                grid[ti+1][tj] = 0;
                q.push({ti+1, tj});
            }
            if ((tj+1 < n) && grid[ti][tj+1]) {
                grid[ti][tj+1] = 0;
                q.push({ti, tj+1});
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0, temp_count;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    flag = 1;
                    temp_count = 0;
                    check_closed(grid, i, j, temp_count);
                    if (flag)
                        count += temp_count;
                }
            }
        }
        return count;
    }
};