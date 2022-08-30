class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i+1; j < matrix.size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0, j = matrix.size()-1; i < j; i++, j--)
            swap(matrix[i], matrix[j]);
        transpose(matrix);
    }
};