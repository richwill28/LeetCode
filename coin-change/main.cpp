class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> fewest(amount + 1, INT_MAX);
        fewest[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (auto& coin : coins) {
                if (i - coin >= 0 && fewest[i - coin] != INT_MAX) {
                    fewest[i] = min(fewest[i - coin] + 1, fewest[i]);
                }
            }
        }
        return (fewest[amount] == INT_MAX) ? -1 : fewest[amount];
    }
};
