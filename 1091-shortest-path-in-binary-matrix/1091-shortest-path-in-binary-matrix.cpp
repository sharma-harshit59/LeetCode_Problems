class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0])
            return -1;
        int dist, m = grid.size(), n = grid[0].size(), flag = 0;
        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            int ti = get<0>(q.front());
            int tj = get<1>(q.front());
            int d = get<2>(q.front());
            if (ti == m-1 && tj == n-1) {
                dist = d;
                flag = 1;
                break;
            }
            q.pop();
            if ((0 <= ti-1) && (0 <= tj-1) && !grid[ti-1][tj-1]) {
                grid[ti-1][tj-1] = 1;
                q.push({ti-1, tj-1, d+1});
            }
            if ((0 <= ti-1) && !grid[ti-1][tj]) {
                grid[ti-1][tj] = 1;
                q.push({ti-1, tj, d+1});
            }
            if ((0 <= ti-1) && (tj+1 < n) && !grid[ti-1][tj+1]) {
                grid[ti-1][tj+1] = 1;
                q.push({ti-1, tj+1, d+1});
            }
            if ((0 <= tj-1) && !grid[ti][tj-1]) {
                grid[ti][tj-1] = 1;
                q.push({ti, tj-1, d+1});
            }
            if ((tj+1 < n) && !grid[ti][tj+1]) {
                grid[ti][tj+1] = 1;
                q.push({ti, tj+1, d+1});
            }
            if ((ti+1 < m) && (0 <= tj-1) && !grid[ti+1][tj-1]) {
                grid[ti+1][tj-1] = 1;
                q.push({ti+1, tj-1, d+1});
            }
            if ((ti+1 < m) && !grid[ti+1][tj]) {
                grid[ti+1][tj] = 1;
                q.push({ti+1, tj, d+1});
            }
            if ((ti+1 < m) && (tj+1 < n) && !grid[ti+1][tj+1]) {
                grid[ti+1][tj+1] = 1;
                q.push({ti+1, tj+1, d+1});
            }
        }
        return flag ? dist+1 : -1;
    }
};