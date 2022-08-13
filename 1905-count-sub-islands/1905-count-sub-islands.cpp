class Solution {
public:
    int m, n, flag;
    
    void check_subisland(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        g2[i][j] = 0;
        while (!q.empty()) {
            int ti = q.front().first, tj = q.front().second;
            q.pop();
            if (!g1[ti][tj])
                flag = 0;
            if ((0 <= ti-1) && g2[ti-1][tj]) {
                q.push({ti-1, tj});
                g2[ti-1][tj] = 0;
            }
            if ((0 <= tj-1) && g2[ti][tj-1]) {
                q.push({ti, tj-1});
                g2[ti][tj-1] = 0;
            }
            if ((ti+1 < m) && g2[ti+1][tj]) {
                q.push({ti+1, tj});
                g2[ti+1][tj] = 0;
            }
            if ((tj+1 < n) && g2[ti][tj+1]) {
                q.push({ti, tj+1});
                g2[ti][tj+1] = 0;
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1[0].size();
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j]) {
                    flag = 1;
                    check_subisland(grid1, grid2, i, j);
                    if (flag)
                        count++;
                }
            }
        }
        return count;
    }
};