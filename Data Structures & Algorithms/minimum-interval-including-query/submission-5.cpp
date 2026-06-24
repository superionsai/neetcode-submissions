class SegmentTree {
public:
    int n;
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int N) {
        this->n = N;
        tree.assign(4 * N, INT_MAX);
        lazy.assign(4 * N, INT_MAX);
    }

    void propagate(int treeidx, int lo, int hi) {
        if (lazy[treeidx] != INT_MAX) {
            tree[treeidx] = min(tree[treeidx], lazy[treeidx]);
            if (lo != hi) {
                lazy[2 * treeidx + 1] = min(lazy[2 * treeidx + 1], lazy[treeidx]);
                lazy[2 * treeidx + 2] = min(lazy[2 * treeidx + 2], lazy[treeidx]);
            }
            lazy[treeidx] = INT_MAX;
        }
    }

    void update(int treeidx, int lo, int hi, int left, int right, int val) {
        propagate(treeidx, lo, hi);

        if (lo > right || hi < left) return;

        if (lo >= left && hi <= right) {
            lazy[treeidx] = min(lazy[treeidx], val);
            propagate(treeidx, lo, hi);
            return;
        }

        int mid = (lo + hi) / 2;
        update(2 * treeidx + 1, lo, mid, left, right, val);
        update(2 * treeidx + 2, mid + 1, hi, left, right, val);

        tree[treeidx] = min(tree[2 * treeidx + 1], tree[2 * treeidx + 2]);
    }

    int query(int treeidx, int lo, int hi, int idx) {
        propagate(treeidx, lo, hi);
        if (lo == hi) return tree[treeidx];

        int mid = (lo + hi) / 2;
        if (idx <= mid) return query(2 * treeidx + 1, lo, mid, idx);
        else return query(2 * treeidx + 2, mid + 1, hi, idx);
    }

    void update(int left, int right, int val) {
        update(0, 0, n - 1, left, right, val);
    }

    int query(int idx) {
        return query(0, 0, n - 1, idx);
    }
};

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> points;

        for (const auto& interval : intervals) {
            points.push_back(interval[0]);
            points.push_back(interval[1]);
        }
        for (int q : queries) {
            points.push_back(q);
        }

        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());

        // compress the coordinates
        unordered_map<int, int> compress;
        for (int i = 0; i < points.size(); ++i) {
            compress[points[i]] = i;
        }

        SegmentTree segTree(points.size());

        for (const auto& interval : intervals) {
            int start = compress[interval[0]];
            int end = compress[interval[1]];
            int len = interval[1] - interval[0] + 1;
            segTree.update(start, end, len);
        }

        vector<int> ans;
        for (int q : queries) {
            int idx = compress[q];
            int res = segTree.query(idx);
            ans.push_back(res == INT_MAX ? -1 : res);
        }

        return ans;
    }
};