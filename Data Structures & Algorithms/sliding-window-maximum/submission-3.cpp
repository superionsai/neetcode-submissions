class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k==1) return nums;
        priority_queue<pair<int, int>> heap;
        int n = nums.size();
        vector<int> windowMax;
        for (int i = 0; i < n; i++) {
            heap.push({nums[i], i});
            if (i >= k-1) {
                while (heap.top().second <= i-k) heap.pop();
                windowMax.push_back(heap.top().first);
            }
        }
        return windowMax;
    }
};
