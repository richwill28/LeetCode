class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCounter = 0;
        for (auto& num : nums) {
            if (num != 0) {
                product *= num;
            } else {
                zeroCounter += 1;
            }
        }

        vector<int> answer;
        if (zeroCounter == 0) {
            for (auto& num : nums) {
                answer.push_back(product / num);
            }
        } else if (zeroCounter == 1) {
            for (auto& num : nums) {
                if (num == 0) {
                    answer.push_back(product);
                } else {
                    answer.push_back(0);
                }
            }
        } else {
            for (auto& num : nums) {
                answer.push_back(0);
            }
        }

        return answer;
    }
};
