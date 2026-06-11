class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<int> total;
        int target = sum/2;
        total.push_back(0);
        
        for (auto stone: stones) {
            int size = total.size();
            for (int i = 0; i < size; i++) {
                if (stone + total[i] == target) return sum - (target*2);
                if (stone + total[i] < target) total.push_back(stone + total[i]);
            }
        }

        int maxSum = 0;
        for (auto it: total) maxSum = max(maxSum, it);

        return sum - (2*maxSum);
    }
};