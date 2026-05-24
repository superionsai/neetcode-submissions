class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0) return 0;
        if (nums.size()==1) return 1;
        sort(nums.begin(), nums.end());
        unordered_map <int, int> counter;
        int maximum = 0;
        counter[nums[0]]++;
        for (int i = 1; i < nums.size(); i++) {
            counter[nums[i]] = counter[(nums[i]-1)] + 1;
            maximum = max(counter[nums[i]], maximum);
        }
        return maximum;
    }
};
