class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> buffer;
        for (auto it: tokens) {
            if (it == "+") {
                int temp = buffer.top();
                buffer.pop();
                temp += buffer.top();
                buffer.pop();
                buffer.push(temp);
            }
            else if (it == "*") {
                int temp = buffer.top();
                buffer.pop();
                temp *= buffer.top();
                buffer.pop();
                buffer.push(temp);
            }
            else if (it == "/") {
                int temp = buffer.top();
                buffer.pop();
                temp = buffer.top()/temp;
                buffer.pop();
                buffer.push(temp);
            }
            else if (it == "-") {
                int temp = buffer.top();
                buffer.pop();
                temp = buffer.top() - temp;
                buffer.pop();
                buffer.push(temp);
            }
            else {
                buffer.push(stoi(it));
            }
        }
        return buffer.top();
    }
};
