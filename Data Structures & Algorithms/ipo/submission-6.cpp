class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = capital.size();
        vector<vector<int>> projects;
        projects.reserve(n);

        for (int i = 0; i < n; i++)
            projects.push_back({capital[i], profits[i]});

        // FIX 1: pass by const reference
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
        };
        sort(projects.begin(), projects.end());

        int cap = w, i = 0, count = 0;

        // FIX 2: comparator captures pointer, not whole vector
        struct Cmp2 {
            const vector<vector<int>>* p;
            bool operator()(int a, int b) const {
                return (*p)[a][1] < (*p)[b][1];
            }
        } cmp2{&projects};
        priority_queue<int, vector<int>, Cmp2> heap(cmp2);

        while (i < n || !heap.empty()) {

            while (i < n && projects[i][0] <= cap) {
                heap.push(i);
                i++;
            }

            if (heap.empty()) break;
            int curr = heap.top();
            heap.pop();                 // FIX 3: pop first

            cap += projects[curr][1];
            count++;

            if (count == k) break;
        }

        return cap;
    }
};
