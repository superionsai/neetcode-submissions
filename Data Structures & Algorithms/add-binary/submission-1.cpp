class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int n = a.size()-1, m = b.size()-1;
        
        char carry = '0';
        while (n >= 0 && m >= 0) {
            if (a[n] == '1' && b[m] == '1') {
                res += carry;
                carry = '1';
            }
            else if (a[n] == '1' || b[m] == '1') {
                if (carry == '1') { 
                    res += '0';  
                }
                else { 
                    res += '1'; 
                }
            }
            else {
                res += carry;
                carry = '0';
            }
            n--; m--;
        }

        if (n > m) {
            while (n >= 0) {
                if (a[n] == '1') {
                    if (carry == '1') res += '0';
                    else { res += '1'; carry = '0'; }
                } else {
                    res += carry;
                    carry = '0';
                }
                n--;
            }
        } else {
            while (m >= 0) {
                if (b[m] == '1') {
                    if (carry == '1') res += '0';
                    else { res += '1'; carry = '0'; }
                } else {
                    res += carry;
                    carry = '0';
                }
                m--;
            }
        }

        if (carry == '1') res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
