class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0]) return 0;
        if (target > nums[nums.size()-1]) return nums.size();
        int left = 0, right = nums.size()-1; 
        int mid;
        while (left <= right) {
            mid = left + (right - left)/2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else return mid; 
        }
        return (nums[left]==target) ? left : (right+1);
    }
};