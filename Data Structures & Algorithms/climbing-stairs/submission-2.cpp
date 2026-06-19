class Solution {
public:
    int climbStairs(int n) {
        if (n==1) return 1;
        if (n==2) return 2;
        vector<int> steps(n+1, 0);
        steps[0] = 1; steps[1] = 1;
        for (int i = 2; i < n+1; i++) {
            steps[i] = steps[i-1] + steps[i-2];
        }
        return steps[n];
    }
};
