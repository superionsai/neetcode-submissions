class Solution {
public:
    int getSum(int a, int b) {
        int carry = 0;
        int n = 0;
        int shift = 0;

        while (shift < 32) {
            int abit = (a >> shift) & 1;
            int bbit = (b >> shift) & 1;

            int buffer = abit ^ bbit;
            int sumBit = buffer ^ carry;

            n |= (sumBit << shift);

            carry = (abit & bbit) | (carry & buffer);

            shift++;
        }

        return n;
    }
};
