class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize all characters
        for (auto &word : words) {
            for (char c : word) indegree[c] = 0;
        }

        // Build graph
        for (int i = 0; i + 1 < words.size(); i++) {
            string &a = words[i];
            string &b = words[i + 1];
            int len = min(a.size(), b.size());
            int j = 0;

            while (j < len && a[j] == b[j]) j++;

            if (j == len) {
                if (a.size() > b.size()) return "";
                continue;
            }

            adj[a[j]].push_back(b[j]);
            indegree[b[j]]++;
        }

        queue<char> q;
        for (auto &it : indegree) {
            if (it.second == 0) q.push(it.first);
        }

        string ans;
        while (!q.empty()) {
            char curr = q.front();
            q.pop();

            ans += curr;
            for (char nei : adj[curr]) {
                indegree[nei]--;
                if (indegree[nei] == 0) q.push(nei);
            }
        }

        if (ans.size() != indegree.size()) return "";
        return ans;
    }
};