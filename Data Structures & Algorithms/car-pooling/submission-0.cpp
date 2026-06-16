class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int L = INT_MAX, R = INT_MIN;
        for (const auto& trip : trips) {
            L = min(L, trip[1]);
            R = max(R, trip[2]);
        }

        int N = R - L + 1;
        vector<int> passChange(N + 1, 0);
        for (const auto& trip : trips) {
            passChange[trip[1] - L] += trip[0];
            passChange[trip[2] - L] -= trip[0];
        }

        int curPass = 0;
        for (int change : passChange) {
            curPass += change;
            if (curPass > capacity) {
                return false;
            }
        }

        return true;
    }
};