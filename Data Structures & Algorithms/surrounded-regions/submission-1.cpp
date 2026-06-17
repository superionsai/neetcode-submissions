class Solution {
private:
    void bfs(int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& X) {
        int r = grid.size(), c = grid[0].size();
        queue <pair<int, int>> buffer;
        buffer.push({n, m}); X[n][m] = false;
        while (!buffer.empty()) {
            auto [a, b] = buffer.front();
            buffer.pop();
            if (a-1 >= 0 && grid[a-1][b]=='O' && X[a-1][b]) 
            { buffer.push({a-1, b}); X[a-1][b] = false; }
            if (b-1 >= 0 && grid[a][b-1]=='O' && X[a][b-1]) 
            { buffer.push({a, b-1}); X[a][b-1] = false; }
            if (a+1 < r && grid[a+1][b]=='O' && X[a+1][b]) 
            { buffer.push({a+1, b}); X[a+1][b] = false; }
            if (b+1 < c && grid[a][b+1]=='O' && X[a][b+1]) 
            { buffer.push({a, b+1}); X[a][b+1] = false; }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> X (n, vector<bool> (m, true));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && X[i][0]) bfs(i, 0, board, X);
            if (board[i][m-1] == 'O' && X[i][m-1]) bfs(i, m-1, board, X);
        }
        for (int k = 0; k < m; k++) {
            if (board[0][k] == 'O' && X[0][k]) bfs(0, k, board, X);
            if (board[n-1][k] == 'O' && X[n-1][k]) bfs(n-1, k, board, X);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (X[i][j]) board[i][j] = 'X';
            }
        }
    }
};
