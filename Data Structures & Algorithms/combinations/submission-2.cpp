class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;

    vector<vector<int>> combine(int n, int k) {
        vector <int> nums;
        for (int i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        combinations(nums, cur, k, 0);
        return res;
    }

    void combinations(vector<int>& nums, vector<int>& cur, int counter, int index) {
        if (index == nums.size()) {
            if (counter == 0) res.push_back(cur);
            return;
        }
        if (counter==0) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[index]);
        combinations(nums, cur, counter-1, index+1);
        cur.pop_back();
        combinations(nums, cur, counter, index+1);
    }
};