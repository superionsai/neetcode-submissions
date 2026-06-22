class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] == '1') {
            return false;
        }

        vector<bool> dp(n, false);
        dp[0] = true;
        int cnt = 0;

        for (int i = 1; i < n; i++) {
            if (i >= minJump && dp[i - minJump]) {
                cnt++;
            }
            if (i > maxJump && dp[i - maxJump - 1]) {
                cnt--;
            }
            if (cnt > 0 && s[i] == '0') {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};