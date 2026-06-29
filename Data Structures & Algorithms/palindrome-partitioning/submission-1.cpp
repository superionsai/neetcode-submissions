class Solution {
public:
    vector<vector<string>> res;
    vector<string> curr;

    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindromes
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPal[i + 1][j - 1]))
                    isPal[i][j] = true;
            }
        }

        dfs(0, s, isPal);
        return res;
    }

    void dfs(int idx, string &s, vector<vector<bool>> &isPal) {
        if (idx == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int j = idx; j < s.size(); j++) {
            if (!isPal[idx][j]) continue;

            curr.push_back(s.substr(idx, j - idx + 1));
            dfs(j + 1, s, isPal);
            curr.pop_back();
        }
    }
};