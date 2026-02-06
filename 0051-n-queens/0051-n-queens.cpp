class Solution {
public:
    vector<vector<string>> ans;
    bool check(vector<string>& board, int row, int col, int n) {
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    // Backtracking 
    void find(int row, int n, vector<string>& board) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (check(board, row, col, n)) {

                board[row][col] = 'Q';     
                find(row + 1, n, board);    
                board[row][col] = '.';      
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.')); 
        find(0, n, board);
        return ans;
    }
};
