class Solution {
public:
    bool issafe(vector<string>& board, int row, int col, int n) {
        // horizoatal
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // vertically
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // diagonally
        // left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // right digoanl
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {

            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void nqueens(vector<string>& board, int row, int n,
                 int   &count) {

        if (row == n) {
            count++;
            return;
        }

        for (int j = 0; j < n; j++) {
            if (issafe(board, row, j, n)) {
                board[row][j] = 'Q';
                nqueens(board, row + 1, n, count);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n){
        vector<string> board(n, string(n, '.'));
        int count=0;
        nqueens(board, 0, n, count);
        return count;
    }
};