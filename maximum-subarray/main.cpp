class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // DP solution (kadane's algorithm)
        int localMax = nums[0];
        int globalMax = localMax;
        for (int i = 1; i < nums.size(); i++) {
            localMax = max(localMax + nums[i], nums[i]);
            globalMax = max(localMax, globalMax);
        }
        return globalMax;
    }
};
