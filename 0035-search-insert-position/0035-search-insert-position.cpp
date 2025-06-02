class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0; 
        int res = nums.size();
        int high = res-1;

        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid]>=target){
                res = mid;
                high = mid - 1;
            }
            else{
                low = mid+1;
            }
        }

        return res;
    }
};

// O(log(n))
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int start = 0, end = nums.size()-1, mid;
//         int res = nums.size();

//         while(start<=end){
//             mid = start + (end - start)/2;

//             if(target==nums[mid]){
//                 return mid;
//             }
//             else if(target>nums[mid]){
//                 start = mid+1;
//             }
//             else{
//                 end = mid-1;
//             }
//         }
//         return start; 
//     }
// };

// O(n)
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]>=target){
//                 return i;
//             }
//         }
//         return nums.size();
        
//     }
// };