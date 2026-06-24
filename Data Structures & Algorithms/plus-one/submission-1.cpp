class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int curr = n-1;
        digits[curr] += 1;

        while (curr > 0 && digits[curr] == 10) {
            digits[curr] = 0;
            digits[--curr] += 1;
        }

        if (curr == 0 && digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
