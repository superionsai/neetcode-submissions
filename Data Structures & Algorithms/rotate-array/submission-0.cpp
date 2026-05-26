class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        int moved = 0;  
        for (int start = 0; moved < n; start++) {
            int first = start;
            int prev = nums[first];
            while (true) {
                int original = (first + k) % n;
                int swapper = original;
                int temp = nums[swapper];
                nums[swapper] = prev;
                prev = temp;
                first = swapper;
                moved++;
                if (first == start) break;
            }
        }
    }
};
