class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        for (int i = 1; i <= target; i++) {
            for (auto& num : nums) {
                if (i - num == 0) {
                    dp[i]++;
                } else if (i - num > 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
