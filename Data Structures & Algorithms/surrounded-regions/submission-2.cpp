class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        queue<pair<int,int>> q;
        q.push({r,c});
        board[r][c] = '#';

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x-1 >= 0 && board[x-1][y] == 'O') { board[x-1][y] = '#'; q.push({x-1,y}); }
            if (x+1 <  n && board[x+1][y] == 'O') { board[x+1][y] = '#'; q.push({x+1,y}); }
            if (y-1 >= 0 && board[x][y-1] == 'O') { board[x][y-1] = '#'; q.push({x,y-1}); }
            if (y+1 <  m && board[x][y+1] == 'O') { board[x][y+1] = '#'; q.push({x,y+1}); }
        }
    }


public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') bfs(i, 0, board);
            if (board[i][m-1] == 'O') bfs(i, m-1, board);
        }
        for (int k = 0; k < m; k++) {
            if (board[0][k] == 'O') bfs(0, k, board);
            if (board[n-1][k] == 'O') bfs(n-1, k, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j]=='#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
