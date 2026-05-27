class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int maxWater = 0;
        while (left < right) {
            maxWater = max(maxWater, (right-left)*(min(heights[left], heights[right])));
            if (heights[left] < heights[right]) left++;
            else if (heights[left] > heights[right]) right--;
            else { left++; right--; }
        }
        return maxWater;
    }
};
