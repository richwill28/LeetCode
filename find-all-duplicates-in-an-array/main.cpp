class Solution {
public:
    // Essentially a hash table solution without using hash table
    // Possible because of 1 <= nums[i] <= n constraint
    // O(n) time and O(1)* space complexity
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        for (auto& num : nums) {
            if (nums[abs(num) - 1] < 0) {
                duplicates.push_back(abs(num));
            }
            if (nums[abs(num) - 1] > 0) {
                // actually no need to check because each element appear only once or twice
                nums[abs(num) - 1] *= -1;
            }
        }
        return duplicates;
    }

    // Improvement from the previous implementation
    // Supports element appearing more than twice
    // O(n) time and O(1)* space complexity
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> hashTable;   // prevent inserting same elements more than once
        for (auto& num : nums) {
            if (nums[abs(num) - 1] < 0) {
                hashTable.insert(abs(num));
            }
            if (nums[abs(num) - 1] > 0) {
                nums[abs(num) - 1] *= -1;
            }
        }

        vector<int> duplicates;
        for (auto& element : hashTable) {
            duplicates.push_back(element);
        }
        return duplicates;
    }

    // *actually should be O(n) space due to nature of the problem
};
