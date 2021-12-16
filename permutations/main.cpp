class Solution {
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& solutionSet, vector<int>& tempSet) {
        if (tempSet.size() == nums.size()) {
            solutionSet.push_back(tempSet); // costs O(tempSet.size())
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (find(tempSet.begin(), tempSet.end(), nums[i]) != tempSet.end()) {
                    // ignore duplicate
                    continue;
                }
                tempSet.push_back(nums[i]);
                backtrack(nums, solutionSet, tempSet);
                tempSet.pop_back();
            }
        }
    }

    void recursivePermute(vector<int>& nums, vector<vector<int>>& solution, int start) {
        if (start == nums.size() - 1) {
            solution.push_back(nums);
        } else {
            for (int i = start; i < nums.size(); i++) {
                swap(nums[start], nums[i]);
                recursivePermute(nums, solution, start + 1);
                swap(nums[start], nums[i]);
            }
        }
    }

public:
    // Backtrack solution
    // Should be O(n * n!) time and O(n!) space complexity
    // If we ignore the solution set, the size complexity is O(n) because at most n-size recursion stack
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solutionSet;
        vector<int> tempSet = {};
        backtrack(nums, solutionSet, tempSet);
        return solutionSet;
    }

    // Iterative solution
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution = {{}};
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> permutation = {};
            for (int j = 0; j < solution.size(); j++) {
                for (int k = 0; k <= solution[j].size(); k++) {
                    vector<int> temp = solution[j];
                    temp.insert(temp.begin() + k, nums[i]);
                    permutation.push_back(temp);
                }
            }
            solution = permutation;
        }
        return solution;
    }

    // Recursive solution
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solution;
        recursivePermute(nums, solution, 0);
        return solution;
    }
};
