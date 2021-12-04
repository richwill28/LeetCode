class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hashMap;
        for (auto& num : nums) {
            auto it = hashMap.find(num);
            if (it != hashMap.end()) {
                return true;
            } else {
                hashMap[num] = true;
            }
        }
        return false;
    }
};
