class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        while (n > 0) {
            if (s[n-1] == ' ') n--;
            else break;
        }
        cout << n << endl;
        int answer = 0;
        while (n > 0) {
            if (s[n-1] == ' ') break;
            answer++;
            n--;
        }
        return answer;
    }
};