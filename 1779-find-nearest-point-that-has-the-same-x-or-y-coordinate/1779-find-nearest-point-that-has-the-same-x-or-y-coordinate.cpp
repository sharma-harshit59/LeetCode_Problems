class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int flag = -1, min_dist = INT_MAX, temp;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x && points[i][1] == y)
                return i;
            else if (points[i][0] == x || points[i][1] == y) {
                temp = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (temp < min_dist) {
                    min_dist = temp;
                    flag = i;
                }
            }
            else;
        }
        return flag;
    }
};