class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> cur;
        backtrack(nums, target, cur, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& cur, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }

        // EXCLUDE branch — skip duplicates
        int next = i + 1;
        while (next < nums.size() && nums[next] == nums[i]) next++;
        backtrack(nums, target, cur, next);

        // INCLUDE branch — always allowed
        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], cur, i + 1);
        cur.pop_back();
    }
};
