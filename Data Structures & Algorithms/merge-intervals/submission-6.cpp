class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int max_val = 0;
        for (const auto& interval : intervals) {
            max_val = max(interval[0], max_val);
        }

        vector<int> mp(max_val + 1, 0);
        for (const auto& interval : intervals) {
            int start = interval[0];
            int end = interval[1];
            mp[start] = max(end + 1, mp[start]);
        }

        vector<vector<int>> res;
        int have = -1;
        int intervalStart = -1;
        for (int i = 0; i < mp.size(); i++) {
            if (mp[i] != 0) {
                if (intervalStart == -1) intervalStart = i;
                have = max(mp[i] - 1, have);
            }
            if (have == i) {
                res.push_back({intervalStart, have});
                have = -1;
                intervalStart = -1;
            }
        }

        if (intervalStart != -1) {
            res.push_back({intervalStart, have});
        }

        return res;
    }
};