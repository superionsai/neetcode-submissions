#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) : cap(capacity), minf(0) {}

    int get(int key) {
        auto it = kv.find(key);
        if (it == kv.end()) return -1;

        int val = it->second.first;
        int f = it->second.second;

        // remove key from current freq list
        freqList[f].erase(itPos[key]);
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minf == f) ++minf;
        }

        // add key to f+1 list at front (most recently used among that freq)
        freqList[f + 1].push_front(key);
        itPos[key] = freqList[f + 1].begin();
        kv[key].second = f + 1;

        return val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        auto it = kv.find(key);
        if (it != kv.end()) {
            // update value and increase frequency
            it->second.first = value;
            get(key); // reuse get to bump frequency and recency
            return;
        }

        // need to evict if at capacity
        if ((int)kv.size() == cap) {
            // evict least frequently used, and least recently used among them (back of list)
            auto &lst = freqList[minf];
            int evictKey = lst.back();
            lst.pop_back();
            if (lst.empty()) freqList.erase(minf);

            kv.erase(evictKey);
            itPos.erase(evictKey);
        }

        // insert new key with freq = 1
        kv[key] = {value, 1};
        freqList[1].push_front(key);
        itPos[key] = freqList[1].begin();
        minf = 1;
    }

private:
    int cap;
    int minf;
    // key -> {value, freq}
    unordered_map<int, pair<int,int>> kv;
    // freq -> list of keys (front = most recently used, back = least recently used)
    unordered_map<int, list<int>> freqList;
    // key -> iterator into its freq list
    unordered_map<int, list<int>::iterator> itPos;
};
