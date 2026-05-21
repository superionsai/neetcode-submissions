class Solution {
public:
    bool isSubsequence(string s, string t) {
        int current = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[current]) ++current;
        }
        return current==s.length() ? true : false;
    }
};