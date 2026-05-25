class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0, back = s.size()-1; int temp;
        while (front < back) {
            temp = int(s[front]);
            while (temp < 48 || (temp > 57 && temp < 65) || (temp > 90 && temp < 97) || temp > 122) {
                front++;
                temp = int(s[front]);
            }
            temp = int(s[back]);
            while (temp < 48 || (temp > 57 && temp < 65) || (temp > 90 && temp < 97) || temp > 122) {
                back--;
                temp = int(s[back]);
            }
            if (front >= back) break;
            cout << s[front] << " " << s[back] << endl;
            if ((char) tolower(s[front]) != (char) tolower(s[back])) return false;
            front++; back--;
        }
        return true;
    }
};
