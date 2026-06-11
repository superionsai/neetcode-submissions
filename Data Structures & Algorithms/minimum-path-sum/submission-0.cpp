class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> Grid(m, vector<int>(n, 0));
        Grid[0][0] = grid[0][0];

        for (int i = 1; i < n; i ++) Grid[0][i] = Grid[0][i-1] + grid[0][i];
        for (int i = 1 ; i < m; i++) Grid[i][0] = Grid[i-1][0] + grid[i][0];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                Grid[i][j] = min(Grid[i][j-1], Grid[i-1][j]) + grid[i][j];
            }
        }
        return Grid[m-1][n-1];
    }
};