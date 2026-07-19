class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);
        return max(nums[0], max(helper(nums1), helper(nums2)));
    }

private:
    int helper(vector<int>& nums) {
        int norob = 0, rob = 0;
        for (int num : nums) {
            int newRob = max(norob + num, rob);
            norob = rob;
            rob = newRob;
        }
        return rob;
    }
};