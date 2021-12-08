class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashMap;
        for (int i = 0; i < s.size(); i++) {
            if (hashMap.find(s[i]) == hashMap.end()) {
                hashMap.insert({s[i], 1});
            } else {
                hashMap[s[i]]++;
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (hashMap.find(t[i]) == hashMap.end()) {
                return false;
            }
            hashMap[t[i]]--;
            if (hashMap[t[i]] < 0) {
                return false;
            }
        }

        for (auto& it : hashMap) {
            if (it.second > 0) {
                return false;
            }
        }

        return true;
    }
};
