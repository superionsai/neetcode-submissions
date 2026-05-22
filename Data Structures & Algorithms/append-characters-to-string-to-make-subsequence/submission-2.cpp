class Solution {
public:
    int appendCharacters(string s, string t) {
        int current_index = 0;
        for (auto it: s) {
            if (it == t[current_index]) {
                current_index++;
            }
        }
        int ans = max(0, int(t.size()-current_index));
        return ans;
    }
};