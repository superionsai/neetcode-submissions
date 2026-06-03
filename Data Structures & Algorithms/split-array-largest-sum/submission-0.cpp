class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector <vector<int>> dp(n+1, vector<int>(k+1, INT_MAX));

        dp[n][0] = 0;
        for (int m = 1; m <= k; m++) {
            for (int i = n-1; i >= 0; i--) {
                int curSum = 0;
                for (int j = i; j < n - m + 1; j++) {
                    curSum += nums[j];
                    dp[i][m] = min(dp[i][m], max(curSum, dp[j+1][m-1]));
                }
            }
        }
        return dp[0][k];
    }
};