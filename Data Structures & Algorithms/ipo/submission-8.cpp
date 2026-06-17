class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;

        for (int i = 0; i < n; i++)
            projects.push_back({capital[i], profits[i]});

        sort(projects.begin(), projects.end());

        priority_queue<int> heap;
        int cap = w, i = 0;

        for (int picked = 0; picked < k; picked++) {

            while (i < n && projects[i].first <= cap) {
                heap.push(projects[i].second);
                i++;
            }

            if (heap.empty())
                break;

            cap += heap.top();
            heap.pop();
        }

        return cap;
    }
};
