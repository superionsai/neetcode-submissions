class Solution {
public:
    int count = 0;

    unordered_set<int> col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

    int totalNQueens(int n) {
        backtrack(0, n);
        return count;
    }

    void backtrack(int r, int n) {
        if (r == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col.count(c) || diag1.count(r - c) || diag2.count(r + c))
                continue;

            col.insert(c);
            diag1.insert(r - c);
            diag2.insert(r + c);

            backtrack(r + 1, n);

            col.erase(c);
            diag1.erase(r - c);
            diag2.erase(r + c);
        }
    }
};