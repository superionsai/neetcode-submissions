class Solution {
public:
    vector<vector<int>> adj;
    vector<int> centroids;
    int nodeB;

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};

        adj.resize(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int nodeA = dfs(0, -1).first;
        nodeB = dfs(nodeA, -1).first;
        findCentroids(nodeA, -1);

        int L = centroids.size();
        if (dfs(nodeA, -1).second % 2 == 0)
            return {centroids[L / 2]};
        else
            return {centroids[L / 2 - 1], centroids[L / 2]};
    }

private:
    pair<int, int> dfs(int node, int parent) {
        int farthestNode = node, maxDistance = 0;
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                auto res = dfs(neighbor, node);
                if (res.second + 1 > maxDistance) {
                    maxDistance = res.second + 1;
                    farthestNode = res.first;
                }
            }
        }
        return {farthestNode, maxDistance};
    }

    bool findCentroids(int node, int parent) {
        if (node == nodeB) {
            centroids.push_back(node);
            return true;
        }
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {
                if (findCentroids(neighbor, node)) {
                    centroids.push_back(node);
                    return true;
                }
            }
        }
        return false;
    }
};