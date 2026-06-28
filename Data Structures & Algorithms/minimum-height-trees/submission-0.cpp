class Solution {
private:
    vector<vector<int>> adj;
    vector<vector<int>> dp;

    void dfs(int node, int parent) {
        for (int nei : adj[node]) {
            if (nei == parent) continue;
            dfs(nei, node);
            int curHgt = 1 + dp[nei][0];
            if (curHgt > dp[node][0]) {
                dp[node][1] = dp[node][0];
                dp[node][0] = curHgt;
            } 
            else if (curHgt > dp[node][1]) {
                dp[node][1] = curHgt;
            }
        }
    }

    void dfs1(int node, int parent, int topHgt) {
        if (topHgt > dp[node][0]) {
            dp[node][1] = dp[node][0];
            dp[node][0] = topHgt;
        } 
        else if (topHgt > dp[node][1]) {
            dp[node][1] = topHgt;
        }

        for (int nei : adj[node]) {
            if (nei == parent) continue;
            int toChild = 1 + ((dp[node][0] == 1 + dp[nei][0]) ? dp[node][1] : dp[node][0]);
            dfs1(nei, node, toChild);
        }
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        dp.assign(n, vector<int>(2, 0)); // top two heights for each node
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        dfs1(0, -1, 0);

        int minHgt = n;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            minHgt = min(minHgt, dp[i][0]);
        }
        for (int i = 0; i < n; i++) {
            if (minHgt == dp[i][0]) {
                res.push_back(i);
            }
        }
        return res;
    }
};