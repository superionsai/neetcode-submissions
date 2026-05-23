class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int, int> counter;
        int current_max = 0;
        int current_num;
        for (auto it : nums) {
            ++counter[it];
            if (counter[it] > current_max) {
                current_num = it;
                current_max = counter[it];
            }
        }
        return current_num;
    }
};