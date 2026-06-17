class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        queue <pair<int, int>> buffer;
        int minutes = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]==2) buffer.push({i, j});
            }
        }

        while (!buffer.empty()) {
            int size = buffer.size();

            while (size--) {
                auto [a, b] = buffer.front();
                buffer.pop();

                if (a-1 >= 0 && grid[a-1][b]==1) { buffer.push({a-1, b}); grid[a-1][b] = 2; }
                if (b-1 >= 0 && grid[a][b-1]==1) { buffer.push({a, b-1}); grid[a][b-1] = 2; }
                if (a+1 < r && grid[a+1][b]==1) { buffer.push({a+1, b}); grid[a+1][b] = 2; }
                if (b+1 < c && grid[a][b+1]==1) { buffer.push({a, b+1}); grid[a][b+1] = 2; }
            }

            if (!buffer.empty()) minutes++;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j]==1) return -1;
            }
        }

        return minutes;
    }
};
