class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }

        if (b == 0) {
            return a;
        }

        int sum = 0;
        int carry = 0;
        int mask = 1;

        // O(32) since mask is unsigned int
        while (mask != 0) {
            int ai = ((a & mask) == 0) ? 0 : 1;
            int bi = ((b & mask) == 0) ? 0 : 1;

            if (ai == 0 && bi == 0) {
                if (carry == 1) {
                    sum |= mask;
                }
                carry = 0;
            } else if ((ai ^ bi) == 1) {
                if (carry == 1) {
                    carry = 1;
                } else {
                    sum |= mask;
                }
            } else {
                if (carry == 1) {
                    sum |= mask;
                }
                carry = 1;
            }

            mask = (unsigned int) mask << 1;
        }

        return sum;
    }
};