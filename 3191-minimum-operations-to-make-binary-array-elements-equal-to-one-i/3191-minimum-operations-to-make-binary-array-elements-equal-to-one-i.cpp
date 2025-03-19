class Solution {
public:
    void flip(vector<int>& nums, int idx){
        for(int i=idx; i<idx+3; i++){
            nums[i] = !nums[i];
        }
    }
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<nums.size()-2; i++){
            if(nums[i]==0){
                count++;
                flip(nums, i);
            }
        }

        for(auto num:nums){
            if(num==0){
                return -1;
            }
        }
        return count;
    }
};