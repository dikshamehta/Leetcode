class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> res(n);
        vector<int> pref(n);
        vector<int> post(n);

        pref[0] = 1;
        post[n - 1] = 1;

        for(int i=1; i<n; i++){
            pref[i] = pref[i-1]*nums[i-1];
        }

        for(int i=n-2; i>=0; i--){
            post[i] = post[i+1] * nums[i+1];
        }

        for(int i=0; i<n; i++){
            res[i] = post[i] * pref[i];
        }

        return res;
    }
};