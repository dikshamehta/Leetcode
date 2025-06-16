class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        // check if 0th index and n-1th index are peak or not
        if(nums[0]>nums[1]){
            // 0th index is peak
            return 0;
        }

        if(nums[n-1]>nums[n-2]){
            // last element is the peak
            return n-1;
        }

        // after all those initial checks apply binary search skipping first and last elem
        int low = 1;
        int high = nums.size()-2;

        while(low<=high){
            int mid = (high+low)/2;

            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            
            if(nums[mid]<nums[mid+1]){
                // peak maybe on right side

                low = mid + 1;
            }
            else{
                // peak maybe on left side
                high = mid - 1;
            }
        }
        return -1;
    }
};