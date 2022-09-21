class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++)
            for (int j = i+1; j < matrix.size(); j++)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = matrix.size()-1;
        while (i < j)
            swap(matrix[i++], matrix[j--]);
        transpose(matrix);
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target)
            return true;
        for (int i = 0; i < 3; i++) {
            rotate(mat);
            if (mat == target)
                return true;
        }
        return false;
    }
};