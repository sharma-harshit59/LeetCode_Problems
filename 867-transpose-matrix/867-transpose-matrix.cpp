class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> temp(m, 0);
        vector<vector<int>> mat(n, temp);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                mat[j][i] = matrix[i][j];
        return mat;
    }
};