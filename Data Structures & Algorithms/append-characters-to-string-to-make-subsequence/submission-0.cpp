class Solution {
public:
    int appendCharacters(string s, string t) {
        int current_index = 0;
        for (auto it: s) {
            if (it == t[current_index]) {
                current_index++;
            }
            if (current_index == t.size()) break;
        }
        return (t.size() - current_index);
    }
};