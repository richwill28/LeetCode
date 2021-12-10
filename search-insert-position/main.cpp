class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }

        int l = 0;
        int r = nums.size();
        int m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] == target) {
                return m;
            } else if (nums[m] < target) {
                l = m + 1;
            } else if (nums[m] > target) {
                r = m;
            }
        }

        return (target > nums[m]) ? m + 1 : m;
    }
};
