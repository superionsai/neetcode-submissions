class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> projects; int n = capital.size();
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return (a[0] < b[0])||(a[0]==b[0] && a[1] > b[1]);
        };
        sort(projects.begin(), projects.end(), cmp);

        int cap = w; int i = 0; int count = 0;
        struct Cmp {
            const vector<vector<int>>* p;
            bool operator()(int a, int b) const {
                return (*p)[a][1] < (*p)[b][1];
            }
        };
        Cmp cmp1{&projects};
        priority_queue <int, vector<int>, decltype(cmp1)> heap(cmp1);
        while (i < n || !heap.empty()) {
            while (i < n && projects[i][0] <= cap) {
                heap.push(i); i++;
            }
            if (heap.empty()) break;
            int curr = heap.top();
            if (projects[curr][1] > 0) {
                cap += projects[curr][1];
                count++;
            }
            if (count == k) break;
            heap.pop();
        }

        return cap;
    }
};