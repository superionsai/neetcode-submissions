class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0; int count = 32;
        while (count--) {
            m = (m << 1) | (n & 1);
            n = n >> 1;
        }
        return m;
    }
};
