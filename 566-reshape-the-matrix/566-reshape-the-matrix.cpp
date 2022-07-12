class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if ((m * n) == (r * c)) {
            vector<int> temp(c);
            vector<vector<int>> res(r, temp);
            int i = 0, j = 0;
            while (i < (m * n)) {
                res[i / c][i % c] = mat[j / n][j % n];
                i++;
                j++;
            }
            return res;
        }
        return mat;
    }
};