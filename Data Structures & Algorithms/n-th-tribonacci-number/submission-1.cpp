class Solution {
    unordered_map<int, int> dp;

public:
    int tribonacci(int n) {
        if (n <= 2) {
            return n == 0 ? 0 : 1;
        }
        if (dp.count(n)) return dp[n];

        dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
        return dp[n];
    }
};