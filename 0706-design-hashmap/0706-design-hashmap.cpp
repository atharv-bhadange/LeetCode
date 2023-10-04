class MyHashMap {
public:
    unordered_map<int,int> mp;
    MyHashMap() {

    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        return mp[key];
    }
    
    void remove(int key) {
        auto it = mp.find(key);
        if(it != mp.end()) {
            mp.erase(it);
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