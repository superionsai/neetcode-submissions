class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack <int> tempG;
        vector <int> result = temperatures;
        for (int i = temperatures.size()-1; i >= 0; i--) {
            while (!tempG.empty() && temperatures[tempG.top()] <= temperatures[i]) 
                tempG.pop();
            if (!tempG.empty()) result[i] = tempG.top() - i;
            else result[i] = 0; 
            tempG.push(i);
        }
        return result;
    }
};
