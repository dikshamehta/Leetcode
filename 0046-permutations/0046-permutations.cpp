
//Approach 2 : Recursion without extra space
//TC: n! * n (finding all perms (n!) in n size loop)
//SC: O(n) + O(n) (Perm, Choosen)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0, nums, res);
        return res;
    }

    void solve( int index, vector<int>& nums, vector<vector<int>>& res){
        // base case
        if(index == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            solve(index+1, nums, res);
            swap(nums[index], nums[i]);
        }

    }
};

// //Approach 1 : Recursion 
// //TC: n! * n (finding all perms (n!) in n size loop)
// //SC: O(n) + O(n) (Perm, Choosen)
// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>> res;
//         vector<int> perm;
//         vector<bool> choosen(nums.size(), false);
//         solve(nums, perm, res, choosen);
//         return res;
//     }

//     void solve(vector<int> &nums, vector<int> &perm, vector<vector<int>> &res, vector<bool> &choosen, int i=0){
//         // base case
//         if(i == nums.size()){
//             res.push_back(perm);
//         }

//         for(int j = 0; j<nums.size(); j++){
//             if(!choosen[j]){
//                 choosen[j] = true;
//                 perm.push_back(nums[j]);
//                 solve(nums, perm, res, choosen, i+1);
//                 perm.pop_back();
//                 choosen[j] = false;
//             }
//         }

//     }
// };