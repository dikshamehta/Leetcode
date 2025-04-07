class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c){
        //check if same char is in row
        for(int i=0; i<9; i++){
            //check if same char is in row
            if(board[row][i] == c) return false;

            //check if same char in col
            if(board[i][col] == c) return false; 
        }
        //check if same char in 3X3 box
        for(int i = (row - (row % 3)); i < (row - (row % 3)) + 3; i++) {
            for(int j = (col - (col % 3)); j < (col - (col % 3)) + 3; j++) {
                if(board[i][j] == c) return false; 
            }
        }

        return true;

    }
    bool solve(vector<vector<char>>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(char c='1'; c<='9'; c++){
                        if(isValid(board, i, j, c)){
                            board[i][j] = c;

                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);  
    }
};