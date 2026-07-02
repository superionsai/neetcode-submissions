class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &f: flights) adj[f[0]].push_back({f[1], f[2]});
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // {cost, stops, node}
        pq.push({0, 0, src});
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int stops = curr[1];
            int u = curr[2];

            if (u == dst) return cost;
            if (stops == k + 1) continue;
            if (cost > dist[u][stops]) continue;

            for (auto &[v, wt] : adj[u]) {
                int newCost = cost + wt;
                if (newCost < dist[v][stops + 1]) {
                    dist[v][stops + 1] = newCost;
                    pq.push({newCost, stops + 1, v});
                }
            }
        }

        return -1;
    }
};