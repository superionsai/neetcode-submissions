class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int maxSize = 1, currSize = 1;
        for (int i = 1; i < n; i++) {
            if ((i%2 == 0 && arr[i-1] > arr[i]) ||
                (i%2 != 0 && arr[i-1] < arr[i])) currSize++;
            else currSize = 1;
            maxSize = max(currSize, maxSize);
        }  
        
        currSize = 1;
        for (int i = 1; i < n; i++) {
            if ((i%2 == 0 && arr[i-1] < arr[i]) ||
                (i%2 != 0 && arr[i-1] > arr[i])) currSize++;
            else currSize = 1;
            maxSize = max(currSize, maxSize);
        }    

        return maxSize;
    }
};