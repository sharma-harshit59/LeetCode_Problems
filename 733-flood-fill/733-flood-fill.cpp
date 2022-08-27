class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({sr, sc});
        int scolor = image[sr][sc], ti, tj;
        while (!q.empty()) {
            ti = q.front().first;
            tj = q.front().second;
            image[ti][tj] = color;
            visited.insert({ti, tj});
            q.pop();
            if ((0 <= ti-1) && (image[ti-1][tj] == scolor))
                q.push({ti-1, tj});
            if ((0 <= tj-1) && (image[ti][tj-1] == scolor))
                q.push({ti, tj-1});
            if ((ti+1 < m) && (image[ti+1][tj] == scolor))
                q.push({ti+1, tj});
            if ((tj+1 < n) && (image[ti][tj+1] == scolor))
                q.push({ti, tj+1});
        }
        return image;
    }
};