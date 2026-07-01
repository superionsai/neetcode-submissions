class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m || (n == m && s != t)) return 0;
        if (n == m) return 1;

        vector<vector<int>> dp (n, vector<int> (m, 0));
        dp[0][0] = (s[0] == t[0]) ? 1 : 0;

        for (int i = 1; i < n; i++) { // check no of subseq.s s has of t[0]
            if (s[i] == t[0]) dp[i][0] += 1;
            dp[i][0] += dp[i-1][0];
        }

        // for i=0 and k from 1 to n, only dp[0][0]. Basically i < k, not possible

        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= min(i, m-1); k++) {
                if (s[i] == t[k]) dp[i][k] += dp[i-1][k-1];
                dp[i][k] += dp[i-1][k];
            }
        }

        return dp[n-1][m-1];
    }
};
