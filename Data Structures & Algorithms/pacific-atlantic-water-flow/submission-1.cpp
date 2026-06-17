class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0},{0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> atl(row, vector<bool>(col, false));

        for (int c = 0; c < col; ++c) {
            dfs(0, c, pac, heights);
            dfs(row - 1, c, atl, heights);
        }
        for (int r = 0; r < row; ++r) {
            dfs(r, 0, pac, heights);
            dfs(r, col - 1, atl, heights);
        }

        vector<vector<int>> res;
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    res.push_back({r, c});
                }
            }
        }
        return res;
    }

private:
    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < heights.size() &&
                nc >= 0 && nc < heights[0].size() &&
                !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};