class Solution {
public:
    void generate( int target, int index, vector<vector<int>>& ans, vector<int>& candidates,vector<int>& comb){
        if(target==0){
            ans.push_back(comb);
            return;
        }
        
        for(int i=index; i<candidates.size(); i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;

            comb.push_back(candidates[i]);
            generate(target-candidates[i], i+1, ans, candidates, comb);
            comb.pop_back();

        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        sort(candidates.begin(), candidates.end()); 

        generate(target, 0, ans, candidates, comb);
        
        return ans;
    }
};

//Solution based on combination sum 1 but giving time limit exceeded
// class Solution {
// public:
//     void generate( int target, int index, set<vector<int>>& ans, vector<int>& candidates,vector<int>& comb){
//         if(index == candidates.size()){
//             if(target == 0){
//                 ans.insert(comb);
//             }
//             return;
//         }

//         if(candidates[index]<=target){
//             comb.push_back(candidates[index]);
//             generate(target-candidates[index], index+1, ans, candidates, comb);
//             comb.pop_back();
//         }

//         //not choose
//         generate(target, index+1, ans, candidates, comb);
//     }
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         set<vector<int>> ans;
//         vector<vector<int>> res;
//         vector<int> comb;
//         sort(candidates.begin(), candidates.end()); 
//         generate(target, 0, ans, candidates, comb);

//         res.assign(ans.begin(), ans.end());
//         return res;
        
//     }
// };