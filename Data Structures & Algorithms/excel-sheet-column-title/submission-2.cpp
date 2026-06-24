class Solution {
public:
    string convertToTitle(int columnNumber) {
        string sol = "";

        while (columnNumber > 0) {
            columnNumber--;                     
            char c = (columnNumber % 26) + 'A'; 
            sol += c;
            columnNumber /= 26;                 
        }

        reverse(sol.begin(), sol.end());        
        return sol;
    }
};
