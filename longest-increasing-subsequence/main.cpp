class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // similar to patience sorting implementation
        set<int> bst;   // for O(log n) insertion
        for (auto& num : nums) {
            if (bst.lower_bound(num) != bst.end()) {
                bst.erase(bst.lower_bound(num));
            }
            bst.insert(num);
        }
        return bst.size();
    }
};
