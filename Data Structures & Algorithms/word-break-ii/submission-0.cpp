class Solution {
public:
    void dfs(string& s, set<string>& dict, vector<string>& perms, string total, string curr, int idx) {
        if (idx == s.size()) {
            if (dict.count(curr)) {
                total += curr;
                perms.push_back(total);
            }
            return;
        }
        
        curr += s[idx]; //directly pass the curr
        dfs(s, dict, perms, total, curr, idx+1);

        if (dict.count(curr)) {
            total += curr + " ";
            dfs(s, dict, perms, total, "", idx+1);
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> perms;
        set<string> dict;
        for (auto it: wordDict) dict.insert(it);

        dfs(s, dict, perms, "", "", 0);
        return perms;
    }
};