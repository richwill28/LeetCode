class Solution {
public:
    // O(a * n) time complexity, where a = 665
    // O(n) size complexity
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hashMap; // map = {sorted string, index}
        int index = 0;
        for (auto& str : strs) {    // costs O(n * 100 log 100) = O(n * 665)
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            if (hashMap.find(sorted) == hashMap.end()) {
                hashMap.insert({sorted, index});
                index++;
            }
        }

        vector<vector<string>> anagrams(index, vector<string>());
        for (auto& str : strs) {    // costs O(n * 100 log 100) = O(n * 665)
            string sorted = str;
            sort(sorted.begin(), sorted.end());
            anagrams[hashMap[sorted]].push_back(str);
        }
        return anagrams;
    }
};
