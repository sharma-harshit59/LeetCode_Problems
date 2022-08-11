class Solution {
public:
    set<pair<int, int>> visited;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int scolor = image[sr][sc];
        image[sr][sc] = color;
        visited.insert({sr, sc});
        if ((0 <= sr-1) && (image[sr-1][sc] == scolor) && !visited.count({sr-1, sc}))
            floodFill(image, sr-1, sc, color);
        if ((sr+1 < image.size()) && (image[sr+1][sc] == scolor) && !visited.count({sr+1, sc}))
            floodFill(image, sr+1, sc, color);
        if ((0 <= sc-1) && (image[sr][sc-1] == scolor) && !visited.count({sr, sc-1}))
            floodFill(image, sr, sc-1, color);
        if ((sc+1 < image[0].size()) && (image[sr][sc+1] == scolor) && !visited.count({sr, sc+1}))
            floodFill(image, sr, sc+1, color);
        return image;
    }
};