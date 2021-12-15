class Solution {
public:
    // O(m + n) time complexity
    string minWindow(string s, string t) {
	    unordered_map<char, int> hashMap;
        for (int i = 0; i < t.size(); i++) {
            hashMap[t[i]]++;
        }

        int begin = 0, end = 0;
        int counter = t.size();
        int start = 0, minLength = INT_MAX;
        while (end < s.size()) {
            if (hashMap[s[end]] > 0) {
                counter--;
            }
            hashMap[s[end]]--;
            end++;
            while (counter == 0) {
                if (end - begin < minLength) {
                    start = begin;
                    minLength = end - begin;
                }
                hashMap[s[begin]]++;
                if (hashMap[s[begin]] > 0) {
                    counter++;
                }
                begin++;
            }
        }

        return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
    }
};
