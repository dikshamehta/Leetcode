class Solution {
public:
    bool isDistinct(const vector<int>& nums, int start) {
        unordered_set<int> s;
        for (int i = start; i < nums.size(); ++i) {
            if (s.count(nums[i])) return false;
            s.insert(nums[i]);
        }
        return true;
    }

    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i <= n; i += 3) {
            if (isDistinct(nums, i)) {
                return i / 3;
            }
        }
        return (n + 2) / 3; // shouldn't be reached unless all elements are removed
    }
};
