class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter = 0;
        int mask = 1;
        while (mask != 0) {
            counter += ((n & mask) == 0) ? 0 : 1;
            mask = (unsigned int) mask << 1;
        }
        return counter;
    }
};
