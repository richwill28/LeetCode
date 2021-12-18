class Solution {
private:
    void backtrack(vector<int>& candidates, vector<vector<int>>& solutionSet, vector<int>& tempSet, int remain, int start) {
        if (remain == 0) {
            solutionSet.push_back(tempSet); // costs O(tempSet.size())
        } else if (remain > 0) {
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i - 1]) {
                    // ignore duplicate
                    continue;
                }
                tempSet.push_back(candidates[i]);
                backtrack(candidates, solutionSet, tempSet, remain - candidates[i], i + 1);
                tempSet.pop_back();
            }
        }
    }

public:
    // Backtracking solution
    // Should be O(k * 2^n) time and O(2^n) space complexity, where k is average length of each possible solution
    // If we ignore the solution set, the space complexity is O(n) because at most n-size recursion stack
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // not optional
        vector<vector<int>> solutionSet;
        vector<int> tempSet = {};
        backtrack(candidates, solutionSet, tempSet, target, 0);
        return solutionSet;
    }
};
