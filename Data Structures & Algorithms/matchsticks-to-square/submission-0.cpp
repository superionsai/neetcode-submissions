class Solution {
public:
    bool dfs(int idx, vector<int>& matchsticks, vector<int>& side, int s) {
        if (idx == matchsticks.size())
            return side[0] == s && side[1] == s &&
                   side[2] == s && side[3] == s;

        for (int i = 0; i < 4; i++) {
            if (side[i] + matchsticks[idx] > s) continue;

            side[i] += matchsticks[idx];
            if (dfs(idx + 1, matchsticks, side, s)) return true;

            side[i] -= matchsticks[idx];
            // Optimization: don't try other empty sides
            if (side[i] == 0)
                break;
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (total % 4) return false;

        int s = total / 4;
        sort(matchsticks.rbegin(), matchsticks.rend());

        if (matchsticks[0] > s) return false;

        vector<int> side(4, 0);
        return dfs(0, matchsticks, side, s);
    }
};