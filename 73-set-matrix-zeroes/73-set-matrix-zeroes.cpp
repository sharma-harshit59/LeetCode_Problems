class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rows.count(i) || cols.count(j))
                    matrix[i][j] = 0;
    }
};