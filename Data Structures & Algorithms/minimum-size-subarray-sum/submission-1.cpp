class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (target==0) return 0;
        int n = nums.size();
        int left = 0, right = 0, sum = nums[right], minimum = n+1;
        while (left <= right && right < n) {
            if (sum >= target) {
                minimum = min(minimum, right-left+1);
                sum -= nums[left];
                left++; 
            }
            else {
                if (right < n-1) right++; else break;
                sum += nums[right];
            }
        }
        return ((minimum<=n) ? minimum : 0);
    }   
};