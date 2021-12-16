class Solution {
private:
    void backtrack(vector<int>& nums, int k, vector<vector<int>>& solutionSet, vector<int>& tempSet, int remain, int start) {
        if (tempSet.size() == k && remain == 0) {
            solutionSet.push_back(tempSet);
        } else if (tempSet.size() < k && remain > 0) {
            for (int i = start; i < nums.size(); i++) {
                tempSet.push_back(nums[i]);
                backtrack(nums, k, solutionSet, tempSet, remain - nums[i], i + 1);
                tempSet.pop_back();
            }
        }
    }

public:
    // Backtracking solution
    // Should be O(9^k) time and O(k) space complexity
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> solutionSet;
        vector<int> tempSet = {};
        backtrack(nums, k, solutionSet, tempSet, n, 0);
        return solutionSet;
    }
};
