class Solution {
public:
    // Linear search implementation (O(sqrt(x)))
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        for (int i = 1; i <= x; i++) {
            if (i <= x / i && (i + 1) > x / (i + 1)) {
                return i;
            }
        }
        return -1;
    }

    // Binary search implementation (O(log n))
    int mySqrt(int x) {
        long l = 0;
        long r = (long) x + 1;
        while (l != r - 1) {
            long m = l + (r - l) / 2;
            if (m <= x / m) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    // Newton's method (O(log n))
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return r;
    }
};
