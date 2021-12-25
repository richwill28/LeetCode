class Solution {
private:
    int robWithRange(vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }

        vector<int> dp(3, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        dp[2] = dp[1];
        for (int i = start + 2; i <= end; i++) {
            dp[2] = max(nums[i] + dp[0], dp[1]);
            dp[0] = dp[1];
            dp[1] = dp[2];
        }
        return dp[2];
    }

public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int frontDP = robWithRange(nums, 0, nums.size() - 2);
        int backDP = robWithRange(nums, 1, nums.size() - 1);
        return frontDP > backDP ? frontDP : backDP;
    }
};
