 // Rotated Sorted Array, then in this case we will be looking for sorted and unsorted halfs

 class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            // check which half is sorted
            if(nums[low]<=nums[mid]){
                // left is sorted
                // left would probably not contain the minimum
                // but just to be on safer side, lets store minimum value in left side as our ans
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            else{
                // right is sorted
                // lets save minimum value in right as part of ans
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
    
};


// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int l = 0, r = nums.size() - 1;

//         while (l < r) {
//             int m = (r + l) / 2;

//             if (nums[m] > nums[r]) {
//                 // Minimum is in the right part
//                 l = m + 1;
//             } else {
//                 // Minimum is in the left part including mid
//                 r = m;
//             }
//         }

//         // l == r, index of minimum element
//         return nums[l];
//     }
// };
