class TimeMap {
private:
    unordered_map <string, vector<pair<int, string>>> keyMap;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!keyMap.count(key)) return "";
        auto &buffer = keyMap[key];
        int left = 0, right = buffer.size(); int mid;
        while (left < right) {
            mid = left + (right - left)/2;
            if (buffer[mid].first <= timestamp) left = mid + 1;
            else right = mid;
        }
        if (left == 0) return "";
        return (buffer[left-1].second);
    }
};
