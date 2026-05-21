class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        map <char, int> letters_s;
        map <char, int> letters_t;
        for (auto letter: s) {
            letters_s[letter]++;
        }
        for (auto letter: t) {
            letters_t[letter]++;
        }
        for (auto it: t) {
            if (letters_t[it] != letters_s[it]) return false;
        }
        return true;
    }
};
