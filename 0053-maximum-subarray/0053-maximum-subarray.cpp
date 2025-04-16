// Brute Force
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         int max_sum = INT_MIN;

//         for(int i=0; i<n; i++){
//             int sum = 0;
//             for(int j=i; j<n; j++){
//                 sum = sum + nums[j];
//                 if(sum>max_sum){
//                     max_sum = sum;
//                 }
//             }
//         }
//         return max_sum;
//     }
// };

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         // we will take an array which will store the maximum sum of certain subarray till the ith position. 
//         // After building the whole array we can find the maximum of the array
//         int size = nums.size();
//         vector<int> dp(size, 0);
//         dp[0] = nums[0];

//         for(int i = 1; i<size; i++){
//             // case 1: when dp[i-1] is positive and zero, then maximum sum at ith position will be dp[i-1]+nums[i]
//             // case 2: dp[i-1] is negative then we will not want to add current value(nums[i]) to it for the max since the value will reduce. We can simply take dp[i] = nums[i]
//             if(dp[i-1]>=0){
//                 dp[i] = dp[i-1] + nums[i];
//             }
//             else{
//                 dp[i] = nums[i];
//             }
//         }
//         // now after array is formed, we can find maximum of it
//         int max_sum = INT_MIN;
//         for(int i = 0; i<size; i++){
//             max_sum = max(max_sum, dp[i]);
//         }

//         return max_sum;
        
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int max_sum = nums[0];
        int prev_sum = nums[0];

        for(int i = 1; i<size; i++){
            if(prev_sum>=0){
                prev_sum = prev_sum + nums[i];
            } else {
                prev_sum = nums[i];
            }
            max_sum = max(max_sum, prev_sum);
        }
        return max_sum;
        
    }
};

