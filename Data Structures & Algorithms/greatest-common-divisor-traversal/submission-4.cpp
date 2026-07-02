class Solution {
public:
    struct DSU {
        vector<int> parent, size;

        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            for (int i = 0; i < n; i++) parent[i] = i;
        }

        int find(int x) {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }

        void unite(int x, int y) {
            x = find(x); y = find(y);
            if (x == y) return;
            if (size[x] < size[y]) swap(x, y);

            parent[y] = x;
            size[x] += size[y];
        }
    };

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        for (int x : nums)
            if (x == 1) return false;

        int mx = *max_element(nums.begin(), nums.end());
        vector<int> spf(mx + 1, 0);

        for (int i = 2; i * i <= mx; i++) {
            if (spf[i]) continue;

            for (int j = i * i; j <= mx; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }

        DSU dsu(n + mx + 1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = (spf[x] == 0 ? x : spf[x]);
                dsu.unite(i, n + p);
                while (x % p == 0) x /= p;
            }
        }

        int root = dsu.find(0);
        for (int i = 1; i < n; i++) {
            if (dsu.find(i) != root) return false;
        }

        return true;
    }
};