class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int res = 1;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) continue;

            int sign = arr[i] > arr[i + 1] ? 1 : 0;
            int j = i + 1;

            while (j < n - 1) {
                if (arr[j] == arr[j + 1]) break;

                int curSign = arr[j] > arr[j + 1] ? 1 : 0;
                if (sign == curSign) break;

                sign = curSign;
                j++;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};