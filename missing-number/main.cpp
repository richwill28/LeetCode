class Solution {
public:
    // using math formula
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (auto& num : nums) {
            sum += num;
        }

        int n = nums.size();
        int missing = (n * (n + 1) / 2) - sum;
        return missing;
    }

    // using bit manipulation
    // based on the fact that x ^ y ^ y = x and XOR operation is commutative
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            missing = missing ^ i ^ nums[i];
        }
        return missing;
    }
};
