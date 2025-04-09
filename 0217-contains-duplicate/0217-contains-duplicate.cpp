class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> sol(nums.begin(), nums.end());

        if(sol.size() == nums.size()){
            return false;
        }
        return true;
        
    }
};