class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j])
                    q.push({i, j, 0});
                mat[i][j] = INT_MAX;
            }
        }
        set<pair<int, int>> visited;
        int ti, tj, d;
        while (!q.empty()) {
            ti = get<0>(q.front());
            tj = get<1>(q.front());
            d = get<2>(q.front());
            mat[ti][tj] = min(mat[ti][tj], d);
            visited.insert({ti, tj});
            q.pop();
            if ((0 <= ti-1) && !visited.count({ti-1, tj}))
                q.push({ti-1, tj, d+1});
            if ((0 <= tj-1) && !visited.count({ti, tj-1}))
                q.push({ti, tj-1, d+1});
            if ((ti+1 < m) && !visited.count({ti+1, tj}))
                q.push({ti+1, tj, d+1});
            if ((tj+1 < n) && !visited.count({ti, tj+1}))
                q.push({ti, tj+1, d+1});
        }
        return mat;
    }
};