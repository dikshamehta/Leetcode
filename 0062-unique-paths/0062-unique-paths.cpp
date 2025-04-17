class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int r = m - 1;
        double res = 1;

        for(int i=0; i<r; i++){
            res = (res * (N-i))/(i+1);
        }
        return (int)res;
    }
};


// class Solution {
// public:
//     vector<vector<int>> dp;
    
//     int helper(int m, int n) {
//         // Base case: If we reach the last row or column, there is only one way.
//         if (m == 1 || n == 1) return 1;
//         // If already computed, return stored result
//         if (dp[m][n] != -1) return dp[m][n];
//         // Store result to avoid redundant calculations
//         return dp[m][n] = helper(m - 1, n) + helper(m, n - 1);
//     }
    
//     int uniquePaths(int m, int n) {
//         // Initialize with -1 
//         dp.resize(m + 1, vector<int>(n + 1, -1));
//         return helper(m, n);
//     }
// };
