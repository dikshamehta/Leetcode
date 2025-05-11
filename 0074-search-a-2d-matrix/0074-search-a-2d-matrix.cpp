class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = n * m - 1;

        while(low<=high){
            int mid = low + (high - low) / 2;
            int r = mid / n;
            int c = mid % n;

            if(matrix[r][c] == target){
                return true;
            }
            else if(matrix[r][c] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
};

// class Solution {
// public:
//     bool binary_search(vector<int>& row, int target){
//         int left = 0; 
//         int right = row.size() - 1;

//         while(left<=right){
//             int mid = left + (right - left) / 2;

//             if(row[mid] == target){
//                 return true;
//             }
//             else if(row[mid] < target){
//                 left = mid + 1;
//             }
//             else{
//                 right = mid - 1;
//             }
//         }
//         return false;
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         for(int i=0; i<m; i++){
//             if(matrix[i][0]<=target && matrix[i][n-1]>=target){
//                 return binary_search(matrix[i], target);
//             }
//         }
//         return false;
//     }
// };


// Brute Force
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();

//         for(int i=0; i<m; i++){
//             for(int j=0; j<n; j++){
//                 if(matrix[i][j] == target){
//                     return true;
//                 }
//             }
//         }

//         return false; 
//     }
// };