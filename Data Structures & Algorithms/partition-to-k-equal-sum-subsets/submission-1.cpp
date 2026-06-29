class Solution {
public:
    bool dfs(int idx, vector<int>& nums, vector<int>& box, int target) {
        if (idx == nums.size()) return true;

        for (int i = 0; i < box.size(); i++) {
            if (box[i] + nums[idx] > target) continue;

            box[i] += nums[idx];
            if (dfs(idx + 1, nums, box, target)) return true;

            box[i] -= nums[idx];
            if (box[i] == 0) break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % k) return false;

        int target = total / k;
        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) return false;
        vector<int> box(k, 0);

        return dfs(0, nums, box, target);
    }
};