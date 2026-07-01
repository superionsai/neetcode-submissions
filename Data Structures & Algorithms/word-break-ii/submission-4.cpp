class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");

        for (int j = 0; j < n; j++) {

            if (dp[j].empty())
                continue;

            string word = "";

            for (int i = j; i < n; i++) {

                word += s[i];

                if (!dict.count(word))
                    continue;

                for (string prev : dp[j]) {
                    if (prev.empty())
                        dp[i + 1].push_back(word);
                    else
                        dp[i + 1].push_back(prev + " " + word);
                }
            }
        }

        return dp[n];
    }
};