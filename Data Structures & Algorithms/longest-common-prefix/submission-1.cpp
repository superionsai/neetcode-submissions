class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = ""; int size = 0;
        char temp;
        while (true) {
            int tag = true;
            temp = strs[0][size];
            for (int i = 0; i < strs.size(); i++) {
                if (size < strs[i].size() && temp == strs[i][size]) continue;
                else {
                    tag = false;
                    break;
                }
            }
            if (!tag) break;
            answer += temp;
            size++;
        }
        return answer;
    }
};