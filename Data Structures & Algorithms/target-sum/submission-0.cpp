class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        if ((total + target) % 2 != 0 || total < abs(target)) 
            return 0;

        int S = (total + target) / 2;

        vector<long long> dp(S + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            for (int s = S; s >= x; s--) {
                dp[s] += dp[s - x];
            }
        }

        return dp[S];
    }
};
