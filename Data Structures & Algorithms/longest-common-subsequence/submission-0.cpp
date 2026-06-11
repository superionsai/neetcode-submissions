class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        if (text1[0] == text2[0]) grid[0][0] = 1;

        for (int i = 1; i < m; i++)   
            grid[i][0] = (text1[i] == text2[0] ? 1 : grid[i-1][0]);

        for (int j = 1; j < n; j++)  
            grid[0][j] = (text1[0] == text2[j] ? 1 : grid[0][j-1]);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = max(grid[i-1][j], grid[i][j-1]);
                if (text1[i] == text2[j])
                    grid[i][j] = max(grid[i][j], grid[i-1][j-1] + 1);
            }
        }
        
        return grid[m-1][n-1];
    }
};
