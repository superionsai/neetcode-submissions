class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if (i == n - 1 && j == n - 1)
                return cost;

            if (i > 0) {
                int newCost = max(cost, grid[i - 1][j]);
                if (newCost < dist[i - 1][j]) {
                    dist[i - 1][j] = newCost;
                    pq.push({newCost, i - 1, j});
                }
            }

            if (i < n - 1) {
                int newCost = max(cost, grid[i + 1][j]);
                if (newCost < dist[i + 1][j]) {
                    dist[i + 1][j] = newCost;
                    pq.push({newCost, i + 1, j});
                }
            }

            if (j > 0) {
                int newCost = max(cost, grid[i][j - 1]);
                if (newCost < dist[i][j - 1]) {
                    dist[i][j - 1] = newCost;
                    pq.push({newCost, i, j - 1});
                }
            }

            if (j < n - 1) {
                int newCost = max(cost, grid[i][j + 1]);
                if (newCost < dist[i][j + 1]) {
                    dist[i][j + 1] = newCost;
                    pq.push({newCost, i, j + 1});
                }
            }
        }

        return -1;
    }
};