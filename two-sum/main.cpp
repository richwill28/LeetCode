class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x = 0;
        int y = 0;

        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto it = hashMap.find(target - nums[i]);
            if (it != hashMap.end() && it->second != i) {
                x = i;
                y = it->second;
                break;
            }
        }
        return {x, y};
    }
};
