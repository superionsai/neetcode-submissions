class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if (n > m) return findMedianSortedArrays(B, A); // ensure A is smaller

        int total = n + m;
        int half = (total + 1) / 2;

        int left = 0, right = n;

        while (left <= right) {
            int i = (left + right) / 2;   // cut in A
            int j = half - i;             // cut in B

            int Aleft  = (i == 0 ? INT_MIN : A[i-1]);
            int Aright = (i == n ? INT_MAX : A[i]);
            int Bleft  = (j == 0 ? INT_MIN : B[j-1]);
            int Bright = (j == m ? INT_MAX : B[j]);

            if (Aleft <= Bright && Bleft <= Aright) {
                // correct partition
                if (total % 2 == 1)
                    return max(Aleft, Bleft);
                return (max(Aleft, Bleft) + min(Aright, Bright)) * 0.5;
            }
            else if (Aleft > Bright) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }

        return 0.0; // unreachable
    }
};
