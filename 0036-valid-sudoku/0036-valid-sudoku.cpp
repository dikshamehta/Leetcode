class Solution {
    bool checkSudoku(vector<vector<char>>& board, int row, int col) {
        char ch = board[row][col];

        int r = 0;
        int c = 0;

        // row check
        r = 0;
        c = col;
        while(r < 9) {
            if(board[r][col] == ch && r != row) return false;
            r++;
        }

        // column check
        r = row;
        c = 0;
        while(c < 9) {
            if(board[row][c] == ch && c != col) return false;
            c++;
        }

        // sub-box check
        int i = 0;
        while(i < 9) {
            r = 3*(row/3) + i/3;
            c = 3*(col/3) + i%3;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch && r != row && c != col) return false;
            i++;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] != '.') {
                    bool ans = checkSudoku(board, row, col);
                    if(ans == false) return false;
                }
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {
//         unordered_map<int, unordered_set<char>> rows, cols;
//         map<pair<int, int>, unordered_set<char>> squares;

//         for(int r=0; r<9; r++){
//             for(int c=0; c<9; c++){
//                 if(board[r][c]=='.') continue;

//                 pair<int, int> sq_idx = {r/3, c/3};

//                 if(rows[r].count(board[r][c]) || cols[c].count(board[r][c]) || squares[sq_idx].count(board[r][c])){
//                     return false;
//                 }

//                 rows[r].insert(board[r][c]);
//                 cols[c].insert(board[r][c]);
//                 squares[sq_idx].insert(board[r][c]);
//             }
//         }
//         return true;
//     }
// };


// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char>>& board) {

//         for(int i = 0; i < 9; i++) {
//             for(int j = 0; j < 9; j++) {
//                 if(board[i][j] != '.') {
//                     // Check the row for duplicates
//                     for(int k = 0; k < j; k++) {
//                         if(board[i][k] == board[i][j]) return false;
//                     }
                    
//                     // Check the column for duplicates
//                     for(int k = 0; k < i; k++) {
//                         if(board[k][j] == board[i][j]) return false;
//                     }

//                     // Check the 3x3 subgrid for duplicates
//                     int startRow = (i / 3) * 3;
//                     int startCol = (j / 3) * 3;
//                     for(int k = startRow; k < startRow + 3; k++) {
//                         for(int l = startCol; l < startCol + 3; l++) {
//                             if(board[k][l] == board[i][j]) return false;
//                         }
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };
