class Solution {
public:
    // Brute force
    // O(n^4)? time and O(n)? space complexity
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (i != j && i != k && j != k) {
                        if (nums[i] + nums[j] + nums[k] == 0) {
                            vector<int> triplet = {nums[i], nums[j], nums[k]};
                            sort(triplet.begin(), triplet.end());   // costs O(1)
                            if (find(triplets.begin(), triplets.end(), triplet) == triplets.end()) {    // maybe costs O(n)?
                                triplets.push_back(triplet);
                            }
                        }
                    }
                }
            }
        }
        return triplets;
    }

    // O(n^2) time and O(n)? space complexity
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end()); // costs O(n log n)
        for (int i = 0; i < nums.size(); i++) {
            int target = 0 - nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while (front < back) {
                int sum = nums[front] + nums[back];
                if (sum == target) {
                    vector<int> triplet = {nums[i], nums[front], nums[back]};
                    triplets.push_back(triplet);

                    // ignore duplicate
                    while (front < back && nums[front] == triplet[1]) {
                        front++;
                    }

                    // ignore duplicate
                    while (front < back && nums[back] == triplet[2]) {
                        back--;
                    }
                } else if (sum < target) {
                    front++;
                } else if (sum > target) {
                    back--;
                }
            }

            // ignore duplicate
            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return triplets;
    }
};
