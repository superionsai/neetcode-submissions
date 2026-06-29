class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();

        vector<int> d1(n), d2(n);
        int count = 0;

        int l = 0, r = -1;

        // Odd
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);

            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
                k++;

            d1[i] = k--;
            count += d1[i];

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
            count += d2[i];

            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }

        return count;
    }
};
