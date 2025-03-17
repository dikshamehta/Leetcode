class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int n:nums){
            freq[n]++;
        }

        for(auto& elem:freq){
            if(elem.second%2!=0){
                return false;
            }
        }
        return true; 
    }
};