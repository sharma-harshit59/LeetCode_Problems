class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        for (int i = 1; i < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    triangle[i][0] += triangle[i-1][0];
                else if (j == i)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
        int M = triangle[m-1][0];
        for (int i = 1; i < m; i++)
            if (triangle[m-1][i] < M)
                M = triangle[m-1][i];
        return M;
    }
};