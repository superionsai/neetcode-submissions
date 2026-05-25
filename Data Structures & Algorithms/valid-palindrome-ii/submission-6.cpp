class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return isPalindrome(s.substr(0, l) + s.substr(l + 1)) || isPalindrome(s.substr(0, r) + s.substr(r + 1));
            }
            l++; r--;
        }
        return true;
    }

private:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++; r--;
        }
        return true;
    }
};