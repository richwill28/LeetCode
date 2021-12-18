class Solution {
public:
    bool isPalindrome(string s) {
        string convertedString = "";
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) {
                convertedString += tolower(s[i]);
            }
        }

        int left = 0;
        int right = convertedString.size() - 1;
        while (left < right) {
            if (convertedString[left] != convertedString[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
