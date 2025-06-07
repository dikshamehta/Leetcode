// note when you get question on duplicates try to solve it for unique
// then see where it fails

// TC = O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low<=high){
            int mid = (low+high)/2;

            if(nums[mid] == target){
                return true;
            }

            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            if(nums[low]<=nums[mid]){
                // left is sorted
                if(nums[low]<=target && target<nums[mid]){
                    // target is in the left half
                    high = mid - 1;
                }
                else{
                    // target is in the right half
                    low = mid + 1;
                }
            }
            else{
                // right is sorted
                if(nums[mid]<target && target<=nums[high]){
                    // target is in right half
                    low = mid + 1;
                }
                else{
                    // target is in left half
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};