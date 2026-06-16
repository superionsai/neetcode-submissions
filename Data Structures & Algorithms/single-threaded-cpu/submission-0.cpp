class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for (int i = 0; i < n; i++) {
            tasks[i].push_back(i);  
        }
        sort(tasks.begin(), tasks.end());

        int time = 0;
        auto cmp = [&](int a, int b) {
            return tasks[a][1] > tasks[b][1];
        };
        priority_queue<int, vector<int>, decltype(cmp)> minHeap(cmp);

        int i = 0;
        vector<int> processOrder;
        while (i < n || !minHeap.empty()) {
            if (minHeap.empty() && time < tasks[i][0])
                time = tasks[i][0];

            while (i < n && tasks[i][0] <= time) {
                minHeap.push(i);
                i++;
            }

            int curr = minHeap.top();
            minHeap.pop();
            processOrder.push_back(tasks[curr][2]);
            time += tasks[curr][1];
        }

        return processOrder;
    }
};
