class Solution {
public:
    int scoreOfString(string s) {
        int answer = 0;
        for (int i =1; i< s.size(); i++) {
            answer += abs(int(s[i]) - int(s[i-1]));
        }
        return answer;
    }
};