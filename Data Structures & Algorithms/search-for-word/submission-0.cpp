class Solution {
public:
    int n, m, len;

    bool dfs(vector<vector<char>>& board, string& word, int a, int b, int idx) {
        if (idx == len)
            return true;

        if (a < 0 || a >= n || b < 0 || b >= m)
            return false;

        if (board[a][b] != word[idx])
            return false;

        char temp = board[a][b];
        board[a][b] = '#';          // mark visited

        bool found =
            dfs(board, word, a - 1, b, idx + 1) ||
            dfs(board, word, a + 1, b, idx + 1) ||
            dfs(board, word, a, b - 1, idx + 1) ||
            dfs(board, word, a, b + 1, idx + 1);

        board[a][b] = temp;         // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        len = word.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};