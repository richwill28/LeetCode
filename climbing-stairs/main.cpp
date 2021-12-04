class Solution {
public:
    int climbStairs(int n) {
        // climbStairs(n) = climbStairs(n - 1) + climbStairs(n - 2)
        int a = 0;
        int b = 1;
        int c;
        for (int i = 1; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};