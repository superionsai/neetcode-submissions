class Solution {
private:
    vector<int> minSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;  
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] >= nums[i])
                dq.pop_back();

            dq.push_back(i);
            if (dq.front() <= i - k)
                dq.pop_front();

            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for (int i = 1; i <= heights.size(); i++) {
            vector <int> minIndex = minSlidingWindow(heights, i);
            for (auto it: minIndex) maxArea = max(maxArea, i*it);
        }
        return maxArea;
    }   
};
