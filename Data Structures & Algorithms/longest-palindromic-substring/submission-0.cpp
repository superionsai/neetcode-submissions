class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<int> d1(n), d2(n);

        int l = 0, r = -1;

        int bestLen = 1;
        int start = 0;

        // Odd
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
                k++;

            d1[i] = k--;

            if (2 * d1[i] - 1 > bestLen) {
                bestLen = 2 * d1[i] - 1;
                start = i - d1[i] + 1;
            }

            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        l = 0;
        r = -1;

        // Even
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);

            while (i - k - 1 >= 0 && i + k < n &&
                   s[i - k - 1] == s[i + k])
                k++;

            d2[i] = k--;

            if (2 * d2[i] > bestLen) {
                bestLen = 2 * d2[i];
                start = i - d2[i];
            }

            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }

        return s.substr(start, bestLen);
    }
};