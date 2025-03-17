class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int num_max = 0;

        for(int n:nums){
            num_max = max(n, num_max);
        }

        vector<bool> freq(num_max+1, false);

        for(int n:nums){
            freq[n] = !freq[n];
        }

        for(int n:nums){
            if(freq[n]){
                return false;
            }
        }
        return true;
    }
};

// class Solution {
// public:
//     bool divideArray(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for(int n:nums){
//             freq[n]++;
//         }

//         for(auto& elem:freq){
//             if(elem.second%2!=0){
//                 return false;
//             }
//         }
//         return true; 
//     }
// };