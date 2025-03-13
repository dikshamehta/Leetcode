class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        bool allZero = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                allZero = false;
                break; 
            }
        }

        if (allZero) return 0; 

        for(int q = 0; q<queries.size(); q++){
            for(int i=queries[q][0]; i<=queries[q][1]; i++){
                if(nums[i]>queries[q][2]){
                    nums[i] -= queries[q][2];
                }
                else{
                    nums[i] = 0;
                }
            }

            bool allZero = true;
            for (int i = 0; i < n; i++) {
                if (nums[i] != 0) {
                    allZero = false;
                    break; 
                }
            }

            if (allZero) return q+1; 

        }
        return -1;
    }
};