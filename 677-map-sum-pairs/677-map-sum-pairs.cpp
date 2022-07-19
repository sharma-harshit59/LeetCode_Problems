class MapSum {
public:
    unordered_map<string, int> smap;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        smap[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        for (auto i: smap) {
            if (i.first.substr(0, prefix.size()) == prefix)
                sum += i.second;
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */