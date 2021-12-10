class Solution {
public:
    // O(n) solution
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        int sum = 0;
        int localMin = 0;
        int globalMin = INT_MAX;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            sum += nums[i];
            localMin++;
            while (sum >= target) {
                globalMin = min(localMin, globalMin);
                sum -= nums[j];
                localMin--;
                j++;
            }
        }

        return (globalMin == INT_MAX) ? 0 : globalMin;
    }
};
