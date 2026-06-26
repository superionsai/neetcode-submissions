class Solution {
private:
    const long long MIN = -2147483648; 
    const long long MAX = 2147483647;

public:
    int reverse(int x) {
        long long n = 0;
        while (x) {
            n = 10*n + (x%10);
            x = x/10;
        }
        return ((MIN <= n) && (n <= MAX)) ? n : 0;
    }
};
