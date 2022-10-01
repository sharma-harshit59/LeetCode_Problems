class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int posi, int posj, char ch) {
        /*
            Check if any cell on the same column has the value same as the proposed value
        */
        for (int i = 0; i < 9; i++)
            if (board[i][posj] == ch)
                return false;
        /*
            Check if any cell on the same row has the value same as the proposed value
        */
        for (int j = 0; j < 9; j++)
            if (board[posi][j] == ch)
                return false;
        /*
            Check if any cell in the corresponding block has the value same as the proposed value
            starti: top-left cell's row number
            startj: top-left cell's column number
            endi:   bottom-right cell's row number
            endj:   bottom-right cell's column number
        */
        int starti = (posi / 3) * 3, startj = (posj / 3) * 3;
        int endi = starti + 3, endj = startj + 3;
        for (int i = starti; i < endi; i++)
            for (int j = startj; j < endj; j++)
                if (board[i][j] == ch)
                    return false;
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) // Has traversed the whole Sudoku Board
            return true;
        if (j == 9) // Reached the end of the row of the Sudoku Board
            return solve(board, i+1, 0);
        if (board[i][j] == '.') { // If the Cell is not filled
            for (char ch = '1'; ch <= '9'; ch++) {
                if (is_valid(board, i, j, ch)) { // Check if the proposed value is valid
                    board[i][j] = ch; // If Valid, place the proposed value in the cell
                    if (solve(board, i, j+1)) // If the sudoku is solved using the  proposed value, return true
                        return true;
                    board[i][j] = '.'; // Else, unfill the cell
                }
            }
        }
        else // If the Cell is filled
            return solve(board, i, j+1);
        return false; // All the possible options have been exhausted, hence there must be some wrong cell-filling in previous calls
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};