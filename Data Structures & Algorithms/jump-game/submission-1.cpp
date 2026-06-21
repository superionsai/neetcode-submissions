class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int currForward = 0;
        for (int i = 0; i < n; i++) {
            if (i > currForward) return false;
            currForward = max(currForward, nums[i] + i);
        }
        return (currForward >= n-1);
    }
};
