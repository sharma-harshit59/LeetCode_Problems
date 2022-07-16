class ParkingSystem {
public:
    unordered_map<int, int> hmap;
    ParkingSystem(int big, int medium, int small) {
        hmap[1] = big;
        hmap[2] = medium;
        hmap[3] = small;
    }
    
    bool addCar(int carType) {
        if (hmap[carType]) {
            hmap[carType]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */