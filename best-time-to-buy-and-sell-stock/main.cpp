class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar = INT_MAX;
        int profitSoFar = 0;
        for (auto& price : prices) {
            minSoFar = min(price, minSoFar);
            profitSoFar = max(price - minSoFar, profitSoFar);
        }
        return profitSoFar;
    }
};
