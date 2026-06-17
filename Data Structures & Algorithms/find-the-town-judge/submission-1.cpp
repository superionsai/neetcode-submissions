class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map <int, pair<int, int>> trustCount;
        for (auto it: trust) {
            trustCount[it[0]].first++;
            trustCount[it[1]].second++;
        }

        for (auto iter: trustCount) {
            if (iter.second.first == 0 && 
                iter.second.second == (n-1)) return iter.first;
        }

        return -1;
    }
};