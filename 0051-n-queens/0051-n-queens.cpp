class Solution {
public:
    bool can_place(int row, int col, vector<string>& board, int n){
        // Check same column
        for(int i = 0; i < row; i++){
            if(board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void place(int row, int n, vector<string>& board, vector<vector<string>>& result){
        if(row == n){
            result.push_back(board); // ✅ no need to convert
            return;
        }

        for(int col = 0; col < n; col++){
            if(!can_place(row, col, board, n)) continue;

            board[row][col] = 'Q';
            place(row + 1, n, board, result);
            board[row][col] = '.'; // backtrack
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        place(0, n, board, result);
        return result;
    }
};
