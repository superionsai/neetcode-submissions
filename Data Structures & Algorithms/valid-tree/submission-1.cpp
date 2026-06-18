class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        vector<bool> visited(n, false);

        map <int, set<int>> adjList;
        for (auto iter: edges) {
            adjList[iter[0]].insert(iter[1]);
            adjList[iter[1]].insert(iter[0]);
        }

        stack <int> buffer;
        buffer.push(0); 
        while (!buffer.empty()) {
            int curr = buffer.top();
            buffer.pop();
            visited[curr] = true;
            for (auto it: adjList[curr]) {
                if (!visited[it]) buffer.push(it);
            }
        }

        for (auto it: visited) {
            if (!it) return false;
        }

        return true;
    }
};
