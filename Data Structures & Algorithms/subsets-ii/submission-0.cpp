class Solution {
    set<vector<int>> res;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, {});
        return vector<vector<int>>(res.begin(), res.end());
    }

    void backtrack(vector<int>& nums, int i, vector<int> subset) {
        if (i == nums.size()) {
            res.insert(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset);
        subset.pop_back();
        backtrack(nums, i + 1, subset);
    }
};