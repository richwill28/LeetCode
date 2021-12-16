class Solution {
private:
    void backtrack(vector<int>& candidates, vector<vector<int>>& solutionSet, vector<int>& tempSet, int remain, int start) {
        if (remain == 0) {
            solutionSet.push_back(tempSet);
        } else if (remain > 0) {
            for (int i = start; i < candidates.size(); i++) {
                tempSet.push_back(candidates[i]);
                backtrack(candidates, solutionSet, tempSet, remain - candidates[i], i); // not i + 1 because we can reuse elements
                tempSet.pop_back();
            }
        }
    }

public:
    // Backtracking solution
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // optional
        vector<vector<int>> solutionSet;
        vector<int> tempSet = {};
        backtrack(candidates, solutionSet, tempSet, target, 0);
        return solutionSet;
    }
};
