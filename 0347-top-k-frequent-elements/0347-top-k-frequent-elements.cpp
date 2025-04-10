class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        // Count frequency of each number
        for (int n : nums) {
            ++count[n];
        }

        // Group numbers by their frequency
        for (const auto& [num, cnt] : count) {
            freq[cnt].push_back(num);
        }

        vector<int> res;
        // Start from the highest possible frequency
        for (int i = freq.size() - 1; i > 0 && res.size() < k; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) break;
            }
        }
        return res;
    }
};
