class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> maxHeap;
        if (a > 0) maxHeap.push({a, 'a'});
        if (b > 0) maxHeap.push({b, 'b'});
        if (c > 0) maxHeap.push({c, 'c'});

        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            if (res.size() > 1 && res[res.size() - 1] == ch && res[res.size() - 2] == ch) {
                if (maxHeap.empty()) break;
                auto [count2, ch2] = maxHeap.top();
                maxHeap.pop();
                res += ch2;
                if (--count2 > 0) maxHeap.push({count2, ch2});
                maxHeap.push({count, ch});
            } 
            else {
                res += ch;
                if (--count > 0) maxHeap.push({count, ch});
            }
        }

        return res;
    }
};