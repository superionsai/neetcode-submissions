class MyHashMap {
private:
    int size = 1000;
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            return a.first < b.first;   // compare only keys
        }
    };
    
    vector<set<pair<int,int>, cmp>> hashMap;

public:
    MyHashMap() {
        hashMap.resize(size);
    }
    
    void put(int key, int value) {
        int index = key % size;

        // erase old key if exists
        auto it = hashMap[index].find({key, 0});
        if (it != hashMap[index].end()) {
            hashMap[index].erase(it);
        }

        // insert new (key, value)
        hashMap[index].insert({key, value});
    }
    
    int get(int key) {
        int index = key % size;

        auto it = hashMap[index].find({key, 0});
        if (it != hashMap[index].end()) {
            return it->second;
        }

        return -1;
    }
    
    void remove(int key) {
        int index = key % size;

        auto it = hashMap[index].find({key, 0});
        if (it != hashMap[index].end()) {
            hashMap[index].erase(it);
        }
    }
};


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */