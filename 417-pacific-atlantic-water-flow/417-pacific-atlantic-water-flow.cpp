class Solution {
public:
    int m, n;
    
    int can_reach(vector<vector<int>>& grid, int i, int j, vector<vector<pair<bool, bool>>>& reach) {
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        bool pflag = false, aflag = false;
        q.push({i, j});
        while (!q.empty() && !(pflag && aflag)) {
            int ti = q.front().first, tj = q.front().second;
            visited.insert({ti, tj});
            q.pop();
            if (ti == 0 || tj == 0 || reach[ti][tj].first)
                pflag = true;
            if (ti == m-1 || tj == n-1 || reach[ti][tj].second)
                aflag = true;
            if ((0 <= ti-1) && !visited.count({ti-1, tj}) && grid[ti-1][tj] <= grid[ti][tj]) {
                q.push({ti-1, tj});
                visited.insert({ti-1, tj});
            }
            if ((0 <= tj-1) && !visited.count({ti, tj-1}) && grid[ti][tj-1] <= grid[ti][tj]) {
                q.push({ti, tj-1});
                visited.insert({ti, tj-1});
            }
            if ((ti+1 < m) && !visited.count({ti+1, tj}) && grid[ti+1][tj] <= grid[ti][tj]) {
                q.push({ti+1, tj});
                visited.insert({ti+1, tj});
            }
            if ((tj+1 < n) && !visited.count({ti, tj+1}) && grid[ti][tj+1] <= grid[ti][tj]) {
                q.push({ti, tj+1});
                visited.insert({ti, tj+1});
            }
        }
        if (pflag && aflag)
            return 3;
        else if (aflag)
            return 2;
        else if (pflag)
            return 1;
        else
            return 0;
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<pair<bool, bool>>> is_valid(m, vector<pair<bool, bool>>(n, {false, false}));
        int flag;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                flag = can_reach(heights, i, j, is_valid);
                if (flag == 3) {
                    res.push_back({i, j});
                    is_valid[i][j] = {true, false};
                }
                else if (flag == 2)
                    is_valid[i][j] = {false, true};
                else if (flag == 1)
                    is_valid[i][j] = {true, false};
                else
                    is_valid[i][j] = {false, false};
            }
        }
        return res;
    }
};