class Solution {
public:
    string minWindow(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        if (tSize > sSize) return "";

        vector<int> tMap(128, 0);
        vector<int> sMap(128, 0);

        for (char c : t)
            tMap[c]++;

        int required = 0;
        for (int i = 0; i < 128; i++)
            if (tMap[i] > 0) required++;

        int formed = 0;
        int left = 0;
        int bestLen = 1000000;
        int bestStart = 0;

        for (int right = 0; right < sSize; right++) {
            char c = s[right];
            sMap[c]++;

            if (tMap[c] > 0 && sMap[c] == tMap[c])
                formed++;

            while (formed == required) {
                if (right - left + 1 < bestLen) {
                    bestLen = right - left + 1;
                    bestStart = left;
                }

                char d = s[left];
                sMap[d]--;
                if (tMap[d] > 0 && sMap[d] < tMap[d])
                    formed--;

                left++;
            }
        }

        if (bestLen == 1000000) return "";
        return s.substr(bestStart, bestLen);
    }
};
