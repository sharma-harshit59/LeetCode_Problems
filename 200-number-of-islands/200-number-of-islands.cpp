class Solution {
public:
    int m, n;
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty()) {
                        int ti = q.front().first;
                        int tj = q.front().second;
                        q.pop();
                        if ((0 <= ti-1) && (grid[ti-1][tj] == '1')) {
                            q.push({ti-1, tj});
                            grid[ti-1][tj] = '0';
                        }
                        if ((ti+1 < m) && (grid[ti+1][tj] == '1')) {
                            q.push({ti+1, tj});
                            grid[ti+1][tj] = '0';
                        }
                        if ((0 <= tj-1) && (grid[ti][tj-1] == '1')) {
                            q.push({ti, tj-1});
                            grid[ti][tj-1] = '0';
                        }
                        if ((tj+1 < n) && (grid[ti][tj+1] == '1')) {
                            q.push({ti, tj+1});
                            grid[ti][tj+1] = '0';
                        }
                    }
                }
            }
        }
        return count;
    }
};