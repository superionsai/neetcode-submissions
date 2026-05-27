class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0; int maxSize = 0;
        unordered_map <char, int> checker;
        for (int i= 0; i < s.length(); i++) {
            if (checker.find(s[i]) != checker.end()) {
                left = max(left, checker[s[i]] + 1);
                checker.erase(s[i]);
            }
            checker[s[i]] = i;
            cout << left << " " << i << endl;
            maxSize = max(maxSize, (i - left + 1));
        }
        return maxSize;
    }
};
