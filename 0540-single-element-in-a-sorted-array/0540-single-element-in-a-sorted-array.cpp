class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-2;

        while(left<=right){
            int mid = (left+right)/2;

            // to check for left half
            // 1st instance -> even index
            // 2nd instance -> odd index
            if(mid%2 == 0){
                if(nums[mid] == nums[mid+1]){
                    // if mid is even and mid and mid+1 are same elements then we are in left half
                    left = mid+1;
                }
                else{
                    // if mid is even and mid and mid+1 are not same elements then we are in right half
                    right = mid-1;
                }
            }
            else{
                if(nums[mid] == nums[mid+1]){
                    // if mid is odd and mid and mid+1 are same elements then we are in right half
                    right = mid-1;
                }
                else{
                    // if mid is odd and mid and mid+1 are not same elements then we are in left half
                    left = mid+1;
                }
            }
            // if(nums[mid] == nums[mid^1])
        }

        return nums[left]; 
        
    }
};