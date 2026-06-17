class Solution {
public:
    struct DSU {
        vector<int> parent, size;
        DSU(int n) {
            parent.resize(n); size.assign(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a; size[a] += size[b];
        }
    };

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        DSU dsu(m*n);
        auto id = [&](int r, int c) { return r*n + c; };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '0') continue;
                if (r > 0 && grid[r-1][c] == '1')
                    dsu.unite(id(r,c), id(r-1,c));
                if (c > 0 && grid[r][c-1] == '1')
                    dsu.unite(id(r,c), id(r,c-1));
            }
        }

        int islands = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') {
                    int root = dsu.find(id(r,c));
                    if (root == id(r,c)) islands++;
                }
            }
        }
        return islands;
    }
};
