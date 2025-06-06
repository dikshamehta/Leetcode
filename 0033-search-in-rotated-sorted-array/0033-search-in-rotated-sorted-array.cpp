class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                return mid;
            }
            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (target > nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;    
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int left = 0;
//         int right = nums.size() - 1;

//         while (left <= right) {
//             int mid = (left + right) / 2;

//             // check if current mid is target or not
//             if (nums[mid] == target) {
//                 return mid;
//             } else if (nums[mid] >= nums[left]) {
//                 // if mid >= left, then we are in left part and everything in between mid and l are sorted
//                 if (nums[left] <= target && target <= nums[mid]) {
//                     // now check if target lie between mid and left
//                     // if yes, explore l to mid-1
//                     right = mid - 1;
//                 } else {
//                     // if not explore mid+1 to right
//                     left = mid + 1;
//                 }
//             } else {
//                 // if mid < left, then we are in right part and everything in between mid and r are sorted
//                 if (nums[mid] <= target && target <= nums[right]) {
//                     // check target lie in mid to r
//                     // if yes explore mid+1 to right
//                     left = mid + 1;
//                 } else {
//                     // if not explore left to mid-1
//                     right = mid - 1;
//                 }
//             }
//         }

//         return -1;        
//     }
// };