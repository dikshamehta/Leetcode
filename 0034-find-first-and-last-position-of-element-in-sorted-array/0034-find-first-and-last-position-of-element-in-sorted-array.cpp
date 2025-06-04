// if not using lower and upper bound concept and use simple binary search
class Solution {
public:
    int findFirst(vector<int>& nums, int target, int n){
        int low = 0;
        int high = n-1;
        int first = -1;

        // with this ran into issue of not handling -1, -1 correctly
        // because first is getting update even if we didnt find the number
        // therefore adding condition to check nums[mid] == target
        // while(low<=high){
        //     int mid = (low+high)/2;
        //     if(nums[mid] >= target){
        //         high = mid-1;
        //         first = mid;
        //     }
        //     else{
        //         low = mid+1;
        //     }
        // }

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return first;
    }

    int findLast(vector<int>& nums, int target, int n){
        int low = 0;
        int high = n-1;
        int last = -1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                last = mid;
                low = mid + 1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        return {findFirst(nums, target, n), findLast(nums, target, n)};
    }
};

// Solved using Lower and Upper Bound Concept
// class Solution {
// public:
//     int lowerBound(vector<int>& nums, int target, int n){
//         int low = 0;
//         int high = n-1;
//         int res = n;

//         while(low<=high){
//             int mid = (low+high)/2;

//             if(nums[mid]>=target){
//                 res = mid;
//                 high = mid-1;
                
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//         return res;
//     }

//     int upperBound(vector<int>& nums, int target, int n){
//         int low = 0;
//         int high = n-1;
//         int res = n;

//         while(low<=high){
//             int mid = (low+high)/2;

//             if(nums[mid]>target){
//                 res = mid;
//                 high = mid-1;
                
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
//         return res;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();
//         int lb = lowerBound(nums, target, n);
        
//         if(lb == n || nums[lb]!= target) return {-1,-1};
//         return {lb, upperBound(nums, target, n)-1};
//     }
// };

// class Solution {
// public:
//     int findFirst(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1, index = -1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] >= target) {
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//             if (nums[mid] == target) index = mid;
//         }
//         return index;
//     }

//     int findLast(vector<int>& nums, int target) {
//         int left = 0, right = nums.size() - 1, index = -1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (nums[mid] <= target) {
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//             if (nums[mid] == target) index = mid;
//         }
//         return index;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         int first = findFirst(nums, target);
//         int last = findLast(nums, target);
//         return {first, last};
//     }
// };
