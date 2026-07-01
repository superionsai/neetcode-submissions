class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<vector<string>> dp(n + 1);

        dp[n].push_back("");

        for (int i = n - 1; i >= 0; i--) {

            for (int len = 1; i + len <= n; len++) {

                string word = s.substr(i, len);

                if (!dict.count(word))
                    continue;

                for (string tail : dp[i + len]) {

                    if (tail.empty())
                        dp[i].push_back(word);
                    else
                        dp[i].push_back(word + " " + tail);
                }
            }
        }

        return dp[0];
    }
};