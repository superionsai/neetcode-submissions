class Solution {
public:
    bool topo(int k, vector<vector<int>>& conditions, vector<int>& pos) {
        vector<vector<int>> adj(k + 1);
        vector<int> indegree(k + 1, 0);
        for (auto& edge : conditions) {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
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

        return idx == k;
    }

    vector<vector<int>> buildMatrix(
        int k,
        vector<vector<int>>& rowConditions,
        vector<vector<int>>& colConditions
    ){
        vector<int> rowArray(k + 1), columnArray(k + 1);
        if (!topo(k, rowConditions, rowArray)) return {};
        if (!topo(k, colConditions, columnArray)) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++) 
            matrix[rowArray[i]][columnArray[i]] = i;

        return matrix;
    }
};