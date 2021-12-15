class Solution {
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& solutionSet, vector<int>& tempSet, int start) {
        solutionSet.push_back(tempSet);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                // ignore duplicate
                continue;
            }
            tempSet.push_back(nums[i]);
            backtrack(nums, solutionSet, tempSet, i + 1);
            tempSet.pop_back();
        }
    }

public:
    // Backtracking solution
    // O(2^n) time and O(2^n) space complexity
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // not optional
        vector<vector<int>> solutionSet;
        vector<int> tempSet = {};
        backtrack(nums, solutionSet, tempSet, 0);
        return solutionSet;
    }

    // Iterative solution
    // O(2^n) time and O(2^n) space complexity
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solutionSet = {{}};
        for (auto& num : nums) {
            int n = solutionSet.size();
            for (int i = 0; i < n; i++) {
                vector<int> subset = {solutionSet[i]};
                subset.push_back(num);
                solutionSet.push_back(subset);
            }
        }
        return solutionSet;
    }
};
