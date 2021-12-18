class Solution {
public:
    // Brute force
    // O(n^3) time and O(1) space complexity
    string longestPalindrome(string s) {
        
    }

    // Dynamic Programming
    // O(n^2) time and O(n^2) space complexity
    string longestPalindrome(string s) {
        int start = 0, maxLength = 1;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                dp[i][j] = (s[i] == s[j]) && (i + 1 >= j - 1 || dp[i + 1][j - 1]);
                if (dp[i][j]) {
                    if (j - i + 1 > maxLength) {
                        start = i;
                        maxLength = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }

    // Expand around center
    // O(n^2) time and O(1) space complexity
    string longestPalindrome(string s) {
        
    }

    // Manacher's Algorithm
    // O(n) time and O(n) space complexity
    string longestPalindrome(string s) {
        
    }
};
