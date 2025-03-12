class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int count = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        while(i<n && nums[i]<=0){
            if(nums[i]==0){
                j++;
            }
            else{
                count++;
            }
            i++;
        }

        return max(count, n-count-j);
    }
};