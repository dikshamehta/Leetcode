class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = (r + l) / 2;

            if (nums[m] > nums[r]) {
                // Minimum is in the right part
                l = m + 1;
            } else {
                // Minimum is in the left part including mid
                r = m;
            }
        }

        // l == r, index of minimum element
        return nums[l];
    }
};
