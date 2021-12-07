class Solution {
public:
    // O(n) implementation
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        unordered_map<char, int> hashMap;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (hashMap.find(s[i]) != hashMap.end()) {
                j = max(hashMap[s[i]] + 1, j);
                hashMap[s[i]] = i;
            }
            hashMap.insert({s[i], i});
            maxLength = max(i - j + 1, maxLength);
        }
        return maxLength;
    }

    // O(n^2) implementation
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        for (int i = 1; i <= s.size(); i++) {
            unordered_set<char> hashTable;
            for (int j = i - 1; j >= 0; j--) {
                if (hashTable.find(s[j]) != hashTable.end()) {
                    break;
                }
                hashTable.insert(s[j]);
                maxLength = max(i - j, maxLength);
            }
        }
        return maxLength;
    }
};
