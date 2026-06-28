class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack({}, nums, 0);
        return res;
    }

    void backtrack(vector<int> perm, vector<int>& nums, int mask) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!(mask & (1 << i))) {
                perm.push_back(nums[i]);
                backtrack(perm, nums, mask | (1 << i));
                perm.pop_back();
            }
        }
    }
};