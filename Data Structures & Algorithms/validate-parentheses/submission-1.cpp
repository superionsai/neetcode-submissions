class Solution {
public:
    bool isValid(string s) {
        stack <char> buffer;
        for (auto it: s) {
            if (it == '(' || it == '{' || it == '[' ) buffer.push(it);
            else {
                if (buffer.empty()) return false;
                char temp = buffer.top();
                if (it == ')' && temp == '(') buffer.pop();
                else if (it == '}' && temp == '{') buffer.pop();
                else if (it == ']' && temp == '[') buffer.pop();
                else return false;
            }
        }
        return (buffer.empty()) ? true : false;
    }
};
