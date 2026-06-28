class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, {});
        return res;
    }

    void backtrack(vector<int>& nums, int i, vector<int> subset) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        // INCLUDE branch
        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset);

        // EXCLUDE branch — skip duplicates
        subset.pop_back();
        int next = i + 1;
        while (next < nums.size() && nums[next] == nums[i]) {
            next++;
        }
        backtrack(nums, next, subset);
    }
};
