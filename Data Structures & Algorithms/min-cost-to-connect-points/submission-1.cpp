class Solution {
public:
    struct DSU {
        vector<int> parent;

        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return;
            parent[x] = y;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);

        int ans = 0;
        int cnt = n;

        for (auto &e : edges) {
            int wt = e[0];
            int u = e[1];
            int v = e[2];

            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                ans += wt;
                cnt--;
                if (!cnt) break;
            }
        }
        return ans;
    }
};