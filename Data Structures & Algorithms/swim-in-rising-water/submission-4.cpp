class Solution {
public:
    struct DSU {
        vector<int> parent;

        DSU(int n) {
            parent.resize(n);
            for (int i = 0; i < n; i++)
                parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int x, int y) {
            x = find(x);
            y = find(y);

            if (x != y)
                parent[x] = y;
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> cells;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());

        DSU dsu(n * n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        for (auto &cell : cells) {
            int h = cell[0];
            int i = cell[1];
            int j = cell[2];

            vis[i][j] = true;

            if (i > 0 && vis[i - 1][j])
                dsu.unite(i * n + j, (i - 1) * n + j);

            if (i < n - 1 && vis[i + 1][j])
                dsu.unite(i * n + j, (i + 1) * n + j);

            if (j > 0 && vis[i][j - 1])
                dsu.unite(i * n + j, i * n + (j - 1));

            if (j < n - 1 && vis[i][j + 1])
                dsu.unite(i * n + j, i * n + (j + 1));

            if (dsu.find(0) == dsu.find(n * n - 1))
                return h;
        }

        return -1;
    }
};