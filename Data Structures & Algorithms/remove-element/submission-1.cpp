class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int current_place = 0;
        int valid_num = 0;
        while (valid_num < nums.size()) {\
            if (nums[valid_num] != val) {
                int temp;
                temp = nums[current_place];
                nums[current_place] = nums[valid_num];
                nums[valid_num] == temp;
                current_place++;
            }
            valid_num++;
        }
        return current_place;
    }
};