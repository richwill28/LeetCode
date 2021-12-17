class Solution {
public:
    // Brute force
    // O(n^2) time and O(1) space complexity
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {
                int area = (j - i) * min(height[i], height[j]);
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }

    // If left line is shorter, moving right line towards left would only decrease the area
    // O(n) time and O(1) space complexity
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            maxArea = max(area, maxArea);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};
