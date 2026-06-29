class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        unordered_set<int> seen;

        int res = 0;
        q.push(0);
        while (!q.empty()) {
            res++;
            for (int i = q.size(); i > 0; i--) {
                int cur = q.front(); q.pop();
                for (int s = 1; s * s + cur <= n; s++) {
                    int next = cur + s * s;
                    if (next == n) return res;
                    if (seen.find(next) == seen.end()) {
                        q.push(next);
                        seen.insert(next);
                    }
                }
            }
        }
        return res;
    }
};