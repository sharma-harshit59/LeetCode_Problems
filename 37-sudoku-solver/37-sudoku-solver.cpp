class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int posi, int posj, char ch) {
        for (int i = 0; i < 9; i++)
            if (board[i][posj] == ch)
                return false;
        for (int j = 0; j < 9; j++)
            if (board[posi][j] == ch)
                return false;
        int starti = (posi / 3) * 3, startj = (posj / 3) * 3;
        int endi = starti + 3, endj = startj + 3;
        for (int i = starti; i < endi; i++)
            for (int j = startj; j < endj; j++)
                if (board[i][j] == ch)
                    return false;
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return true;
        if (j == 9)
            return solve(board, i+1, 0);
        if (board[i][j] == '.') {
            for (char ch = '1'; ch <= '9'; ch++) {
                if (is_valid(board, i, j, ch)) {
                    board[i][j] = ch;
                    if (solve(board, i, j+1))
                        return true;
                    board[i][j] = '.';
                }
            }
        }
        else
            return solve(board, i, j+1);
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};