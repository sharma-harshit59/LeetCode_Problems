class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& points) {
        int x1, x2, x3, y1, y2, y3;
        for (int i = 2; i < points.size(); i++) {
            x1 = points[i-2][0];
            x2 = points[i-1][0];
            x3 = points[i][0];
            y1 = points[i-2][1];
            y2 = points[i-1][1];
            y3 = points[i][1];
            
            if (((y2 - y1) * (x3 - x2)) != ((y3 - y2) * (x2 - x1)))
                return false;
        }
        return true;
    }
};