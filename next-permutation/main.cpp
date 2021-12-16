class Solution {
public:
    // O(n) time and O(1) size complexity
    void nextPermutation(vector<int>& nums) {
        int k;
        for (k = nums.size() - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }

        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int l;
        for (l = nums.size() - 1; l > k; l--) {
            if (nums[l] > nums[k]) {
                break;
            }
        }

        swap(nums[k], nums[l]);
        reverse(nums.begin() + (k + 1), nums.end());
    }
};
