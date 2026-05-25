class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m+n-1; i >= n; i--) {
            nums1[i] = nums1[i-n];
        }
        int current = 0, p1 = n, p2 = 0;
        while (p1 < m+n && p2 < n) {
            if (nums1[p1] <= nums2[p2]) {
                nums1[current] = nums1[p1];
                p1++; current++;
            }
            else {
                nums1[current] = nums2[p2];
                p2++; current++;
            }
        }
        while (p1 < m+n) {
            nums1[current] = nums1[p1];
            p1++; current++;
        }
        while (p2 < n) {
            nums1[current] = nums2[p2];
            p2++; current++;
        }
    }
};