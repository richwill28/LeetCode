class Solution {
public:
    string getPermutation(int n, int k) {
        // create number set
        vector<int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }

        // create factorial lookup array (optional, for efficiency)
        vector<int> factorial(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            factorial[i] = i * factorial[i - 1];
        }

        k--;    // 0-based indexing
        string sequence = "";
        for (int i = 1; i <= n; i++) {
            int index = k / factorial[n - i];
            sequence += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k -= index * factorial[n - i];
        }
        return sequence;
    }
};
