class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(), count = 0;
        vector<vector<int>> grid_T = grid;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) 
                swap(grid_T[i][j], grid_T[j][i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i] == grid_T[j])
                    count++;
        return count;
    }
};