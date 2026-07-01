class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (!dict.count(word)) continue;

                for (string prev : dp[j]) {
                    if (prev.empty())
                        dp[i].push_back(word);
                    else
                        dp[i].push_back(prev + " " + word);
                }
            }
        }

        return dp[n];
    }
};