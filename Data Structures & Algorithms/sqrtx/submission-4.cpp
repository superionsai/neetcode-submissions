class Solution {
public:
    int mySqrt(int x) {
        long long X = x;
        long long left = 0, right = x; long long mid;
        while (left < right) {
            mid = left + (right - left)/2;
            if (mid*mid <= X) {
                if ((mid+1)*(mid+1) > X) return mid;
                else left = mid + 1;
            }
            else right = mid - 1;
        }
        return left;
    }
};