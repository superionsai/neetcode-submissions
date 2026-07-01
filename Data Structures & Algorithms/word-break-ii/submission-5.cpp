class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int maxLen = 0;
        for (auto &w : wordDict)
            maxLen = max(maxLen, (int)w.size());

        vector<vector<string>> dp(n + 1);
        dp[n].push_back("");

        for (int i = n - 1; i >= 0; i--) {

            string word = "";

            for (int j = i; j < n && j < i + maxLen; j++) {

                word += s[j];

                if (!dict.count(word))
                    continue;

                for (string tail : dp[j + 1]) {
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