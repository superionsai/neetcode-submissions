class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int current_great = arr[n-1]; arr[n-1] = -1; int temp;
        for (int i = n-2; i >= 0; i--) {
            temp = arr[i];
            arr[i] = current_great;
            current_great = max(current_great, temp);
        }
        return arr;
    }
};