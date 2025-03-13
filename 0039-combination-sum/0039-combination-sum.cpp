class Solution {
public:
    void generate( int target, int index, vector<vector<int>>& ans, vector<int>& candidates,vector<int>& comb){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(comb);
            }
            return;
        }

        if(candidates[index]<=target){
            comb.push_back(candidates[index]);
            generate(target-candidates[index], index, ans, candidates, comb);
            comb.pop_back();
        }

        //not choose
        generate(target, index+1, ans, candidates, comb);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        generate(target, 0, ans, candidates, comb);

        return ans;
        
    }
};