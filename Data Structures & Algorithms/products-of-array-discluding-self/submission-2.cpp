class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        if (n == 2) return {nums[1], nums[0]};
        vector<int> prefixProd = {nums[0]};
        vector <int> suffixProd = nums;
        for (int i = 1; i < n-1; i++) {
            prefixProd.push_back(prefixProd[i-1]*nums[i]);
            suffixProd[n-i-1] = suffixProd[n-i]*nums[n-i-1]; 
        }

        vector <int> output(n, 1);
        for (int i = 1; i < n-1; i++) {
            output[i] = prefixProd[i-1]*suffixProd[i+1];
        }
        output[0] = suffixProd[1]; output[n-1] = prefixProd[n-2];
        return output;
    }
};
