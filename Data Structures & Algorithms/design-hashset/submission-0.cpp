class MyHashSet {
private:
    int size = 10000;
    vector<set<int>> hashSet;

public:
    MyHashSet() {
        hashSet.resize(size);
    }
    
    void add(int key) {
        int index = key%size;
        hashSet[index].insert(key);
    }
    
    void remove(int key) {
        int index = key%size;
        try { 
            hashSet[index].erase(key);
        }
        catch (...) {
            return;
        }
    }
    
    bool contains(int key) {
        int index = key%size;
        return (hashSet[index].find(key) != hashSet[index].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */