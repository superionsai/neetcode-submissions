class Solution {
public:
    vector<vector<int>> buildMatrix(
        int k,
        vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions
    ) {
        vector<int> rowArray(k + 1), columnArray(k + 1);
        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1);
        queue<int> q;

        for (int t = 0; t < 2; t++) {
            vector<vector<int>>& conditions = (t == 0 ? rowConditions : colConditions);
            vector<int>& pos = (t == 0 ? rowArray : columnArray);
            for (int i = 1; i <= k; i++) {
                adj[i].clear();
                indegree[i] = 0;
            }

            while (!q.empty()) q.pop();
            for (auto& edge : conditions) {
                adj[edge[0]].push_back(edge[1]);
                indegree[edge[1]]++;
            }
            for (int i = 1; i <= k; i++) {
                if (indegree[i] == 0) q.push(i);
            }

            int idx = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                pos[node] = idx++;
                for (int nei : adj[node]) {
                    indegree[nei]--;
                    if (indegree[nei] == 0) q.push(nei);
                }
            }
            if (idx != k) return {};
        }

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++)
            matrix[rowArray[i]][columnArray[i]] = i;

        return matrix;
    }
};