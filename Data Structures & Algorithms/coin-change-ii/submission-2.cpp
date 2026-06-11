class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(), m = amount+1;
        sort(coins.begin(), coins.end());
        vector <vector<int>> grid (m, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            grid[0][i] = 1; 
        }
        for (int j = 0; j < m; j++) {
            grid[j][0] = (j % coins[0] == 0);
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i][j-1];
                if (i >= coins[j]) grid[i][j] += grid[i - coins[j]][j];
            }
        }

        return grid[m-1][n-1];
    }
};
