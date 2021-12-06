class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hashTable;    // optional, for convenience using find()
        for (auto& word : wordDict) {
            hashTable.insert(word);
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                bool hasSubstring = hashTable.find(s.substr(j, i - j)) != hashTable.end();
                if (dp[j] && hasSubstring) {
                    dp[i] = true;
                    break;  // optional speed-up
                }
            }
        }

        return dp[s.size()];
    }
};
