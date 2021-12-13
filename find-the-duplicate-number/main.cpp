class Solution {
public:
    // O(n log n) time and O(1) space complexity
    // Modifying input array by sorting
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return 0;
    }

    // Turtoise and Hare (Floyd's cycle-finding algorithm)
    // O(n) time and O(1) space complexity
    // Without modifying input array
    int findDuplicate(vector<int>& nums) {
        int turtoise = nums[0];
        int hare = nums[nums[0]];
        while (turtoise != hare) {
            turtoise = nums[turtoise];
            hare = nums[nums[hare]];
        }

        turtoise = 0;
        while (turtoise != hare) {
            turtoise = nums[turtoise];
            hare = nums[hare];
        }
        return turtoise;
    }

    // Pigeonhole principle
    // O(n^2) time and O(1) space complexity
    // Without modifying input array
    int findDuplicate(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            int count = 0;
            for (auto& num : nums) {
                if (num <= i) {
                    count++;
                }
            }
            if (count <= i) {
                return i + 1;
            }
        }
        return 0;
    }

    // Pigeonhole principle (improved implementation using binary search)
    // O(n log n) time and O(1) space complexity
    // Without modifying input array
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = 0;
            for (auto& num : nums) {
                if (num <= mid) {
                    count++;
                }
            }
            if (count <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
