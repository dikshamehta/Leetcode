class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len_nums = nums.size();
        unordered_set<int> unique_nums;
        for(int i=0; i<len_nums; i++){
            unique_nums.insert(nums[i]);
        }

        if(len_nums==unique_nums.size()){
            return false;
        }
        else{
            return true;
        }

        
    }
};