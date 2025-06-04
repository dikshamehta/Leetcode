class Solution {
public:
    int lowerBound(vector<int>& nums, int target, int n){
        int low = 0;
        int high = n-1;
        int res = n;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]>=target){
                res = mid;
                high = mid-1;
                
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }

    int upperBound(vector<int>& nums, int target, int n){
        int low = 0;
        int high = n-1;
        int res = n;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]>target){
                res = mid;
                high = mid-1;
                
            }
            else{
                low = mid + 1;
            }
        }
        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, target, n);
        
        if(lb == n || nums[lb]!= target) return {-1,-1};
        return {lb, upperBound(nums, target, n)-1};
    }
};

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
