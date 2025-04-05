class Solution {
public:
    bool can_place(int i, int q, vector<vector<bool>>& board, int n){
        for(int j = q - 1; j >= 0; j--){
            if(board[i][j]) return false;
        }

        for(int j = q - 1, i2 = i - 1; j >= 0 && i2 >= 0; j--, i2--){
            if(board[i2][j]) return false;
        }

        for(int j = q - 1, i2 = i + 1; j >= 0 && i2 < n; j--, i2++){
            if(board[i2][j]) return false;
        }

        return true;
    }
    void place(vector<vector<bool>>& board, int q, int n, vector<vector<string>>& result){
        if(q==n){
            vector<string> config;
            for(int i = 0; i < n; i++){
                string row = "";
                for(int j = 0; j < n; j++){
                    row += (board[i][j] ? 'Q' : '.');
                }
                config.push_back(row);
            }
            result.push_back(config);
            return;
        }

        for(int i=0; i<n; i++){
            if(!can_place(i, q, board, n)) continue;

            board[i][q] = true;
            place(board, q+1, n, result);
            board[i][q] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        vector<vector<string>> result;
        place(board, 0, n, result);
        return result;
    }
};