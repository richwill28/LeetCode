class Solution {
public:
    // using C++ built-in function
    vector<int> countBits(int n) {
        vector<int> out;
        for (int i = 0; i <= n; i++) {
            out.push_back(__builtin_popcount(i));
        }
        return out;
    }

    // DP solution
    vector<int> countBits(int n) {
        vector<int> out(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            out[i] = out[i >> 1] + (i % 2);
        }
        return out;
    }
};
