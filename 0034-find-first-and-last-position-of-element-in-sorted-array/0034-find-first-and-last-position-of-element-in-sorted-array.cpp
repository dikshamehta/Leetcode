class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) index = mid;
        }
        return index;
    }

    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (nums[mid] == target) index = mid;
        }
        return index;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};
