class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};
        for (int num : nums) {
            vector<vector<int>> new_perms;
            for (const auto& p : perms) {
                for (int i = 0; i <= p.size(); i++) {
                    vector<int> p_copy = p;
                    p_copy.insert(p_copy.begin() + i, num);
                    new_perms.push_back(p_copy);
                }
            }
            perms = new_perms;
        }
        return perms;
    }
};