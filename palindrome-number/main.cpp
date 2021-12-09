class Solution {
public:
    // convert integer to string
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string str = to_string(x);
        int left = 0;
        int right = str.size() - 1;
        while (left <= right) {
            if (str[left] != str[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }

    // reverse half the digits
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else if (x > 0 && x % 10 == 0) {
            return false;
        }

        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }

        return (x == rev) || (x == rev / 10);
    }
};
