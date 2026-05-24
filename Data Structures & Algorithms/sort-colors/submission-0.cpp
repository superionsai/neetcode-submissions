class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counter_0 = 0, counter_1 = 0, counter_2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]==0) counter_0++;
            if (nums[i]==1) counter_1++;
            if (nums[i]==2) counter_2++;
        }   
        for (int i = 0; i < nums.size(); i++) {
            if (counter_0) { nums[i] = 0; --counter_0;}
            else if (counter_1) { nums[i] = 1; --counter_1; }
            else if (counter_2) { nums[i] = 2; --counter_2; }
        }
    }
};