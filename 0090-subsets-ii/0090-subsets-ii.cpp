class Solution {
public:
    void generate(int level, vector<int>& subset, vector<int>& nums, vector<vector<int>>& ans) {
        ans.push_back(subset);

        for(int i=level; i<nums.size(); i++){
            if(i!=level && nums[i]==nums[i-1]) continue;

            subset.push_back(nums[i]);
            generate(i+1, subset, nums, ans);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        generate(0, subset, nums, ans);

        return ans;
    }
};

//Brute Force
// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         set<vector<int>> res;
//         vector<vector<int>> r;
//         vector<int> sub;
//         int i = 0;
//         sort(nums.begin(), nums.end());
//         generate(nums, res, sub, i);
//         for (set<vector<int>>::iterator itr = res.begin(); itr != res.end(); itr++) {
//             r.push_back(*itr);
//             // for(int j : *itr){
//             //     cout << j << " ";
//             // }
//             // cout<<endl; 
//         }
//         return r;
//     }

//     void generate(vector<int>& nums, set<vector<int>> &res, vector<int> &sub, int i){
//         //Base Case
//         if(i == nums.size()){
//             res.insert(sub);
//             return;
//         }

//         //case 0
//         generate(nums, res, sub, i+1);

//         //case 1
//         sub.push_back(nums[i]);
//         generate(nums, res, sub, i+1);
//         sub.pop_back();

//         return;
//     }
// };