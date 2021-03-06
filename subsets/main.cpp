class Solution {
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& solutionSet, vector<int>& tempSet, int start) {
        solutionSet.push_back(tempSet);
        for (int i = start; i < nums.size(); i++) {
            tempSet.push_back(nums[i]);
            backtrack(nums, solutionSet, tempSet, i + 1);
            tempSet.pop_back();
        }
    }

public:
    // Backtracking solution
    // O(2^n) time and O(2^n) space complexity
    // If we ignore the solution set, the size complexity is O(n) because at most n-size recursion stack and n-size copying list
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // optional
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
