class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> grid(n + 2, vector<int>(n + 2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                grid[i][j] = prices[j] - prices[i];
            }
        }

        vector<int> dp(n + 2, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            for (int j = i + 1; j < n; j++) {
                int profit = grid[i][j] + dp[j + 2];
                dp[i] = max(dp[i], profit);
            }
        }

        return dp[0];
    }
};
