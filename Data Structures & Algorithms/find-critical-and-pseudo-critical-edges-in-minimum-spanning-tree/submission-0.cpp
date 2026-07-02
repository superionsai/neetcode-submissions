class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        int maxSize;

        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            maxSize = 1;
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        bool unite(int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y) return false;
            if (size[x] < size[y]) swap(x, y);

            parent[y] = x;
            size[x] += size[y];
            maxSize = max(maxSize, size[x]);

            return true;
        }
    };

    int mst(int n, vector<vector<int>>& edges, int skip, int force) {
        DSU dsu(n);
        int weight = 0;

        if (force != -1) {
            dsu.unite(edges[force][0], edges[force][1]);
            weight += edges[force][2];
        }
        for (int i = 0; i < edges.size(); i++) {
            if (i == skip) continue;
            if (dsu.unite(edges[i][0], edges[i][1])) weight += edges[i][2];
        }
        if (dsu.maxSize != n) return INT_MAX;

        return weight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
            [](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });

        int mstWeight = mst(n, edges, -1, -1);
        vector<int> critical, pseudo;

        for (int i = 0; i < edges.size(); i++) {
            if (mst(n, edges, i, -1) > mstWeight) {
                critical.push_back(edges[i][3]);
            }
            else if (mst(n, edges, -1, i) == mstWeight) {
                pseudo.push_back(edges[i][3]);
            }
        }

        return {critical, pseudo};
    }
};