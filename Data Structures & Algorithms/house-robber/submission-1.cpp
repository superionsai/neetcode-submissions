class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int rob = nums[0];
        int norob = 0;
        for (int i = 1; i < nums.size(); i++) {
            int newRob = norob + nums[i];
            int nonewRob = max(norob, rob);
            rob = newRob;
            norob = nonewRob; 
        }

        return max(rob, norob);
    }
};