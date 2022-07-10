class SmallestInfiniteSet {
public:
    unordered_set<int> deleted;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        int i = 1;
        while (deleted.count(i))
            i++;
        deleted.insert(i);
        return i;
    }
    
    void addBack(int num) {
        if (deleted.count(num))
            deleted.erase(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */