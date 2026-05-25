class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 0, swapper = 0;
        while (swapper < nums.size()) {
            swap(nums[dup], nums[swapper]);
            swapper++;
            if (swapper < nums.size() && nums[dup] == nums[swapper]) {
                while(swapper < nums.size() && nums[dup]==nums[swapper]) swapper++;
            }
            dup++;
        }
        return dup;
    }
};