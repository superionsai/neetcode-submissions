class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> indegree(n, vector<int>(m, 0));

        // Build indegrees
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && matrix[i][j] < matrix[i-1][j]) indegree[i-1][j]++;
                if (i < n-1 && matrix[i][j] < matrix[i+1][j]) indegree[i+1][j]++;
                if (j > 0 && matrix[i][j] < matrix[i][j-1]) indegree[i][j-1]++;
                if (j < m-1 && matrix[i][j] < matrix[i][j+1]) indegree[i][j+1]++;
            }
        }

        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (indegree[i][j] == 0)
                    q.push({i, j});
            }
        }

        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            ans++;

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                if (i > 0 && matrix[i][j] < matrix[i-1][j]) {
                    indegree[i-1][j]--;
                    if (indegree[i-1][j] == 0) q.push({i-1, j});
                }

                if (i < n-1 && matrix[i][j] < matrix[i+1][j]) {
                    indegree[i+1][j]--;
                    if (indegree[i+1][j] == 0) q.push({i+1, j});
                }

                if (j > 0 && matrix[i][j] < matrix[i][j-1]) {
                    indegree[i][j-1]--;
                    if (indegree[i][j-1] == 0) q.push({i, j-1});
                }

                if (j < m-1 && matrix[i][j] < matrix[i][j+1]) {
                    indegree[i][j+1]--;
                    if (indegree[i][j+1] == 0) q.push({i, j+1});
                }
            }
        }

        return ans;
    }
};