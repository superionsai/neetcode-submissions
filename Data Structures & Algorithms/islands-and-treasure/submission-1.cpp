class Solution {
public:
    int ROWS, COLS;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int INF = INT_MAX;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        queue<pair<int,int>> q;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& d : directions) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS &&
                    grid[nr][nc] == INF) {

                    grid[nr][nc] = grid[r][c] + 1;  
                    q.push({nr, nc});
                }
            }
        }
    }
};
