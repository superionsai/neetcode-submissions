class Solution {
public:
    string simplifyPath(string path) {
        stack <string> comms;
        string temp;
        for (auto it: path) {
            if (it == '/') {
                if (temp != "") comms.push(temp);
                temp = "";
            }
            else {
                temp += it;
            }
        }
        if (temp != "") comms.push(temp);

        string parsedPath = ""; int popCount = 0;
        while (!comms.empty()) {
            temp = comms.top();
            if (temp == "..") {
                popCount++;
                comms.pop();
            }
            else if (temp == ".") { comms.pop(); }
            else {
                if (popCount) { 
                    popCount--; 
                    comms.pop(); 
                }
                else {
                    parsedPath = ('/' + temp + parsedPath);
                    comms.pop();
                }
            }
        }
        
        return (parsedPath=="") ? "/" : parsedPath;
    }
};