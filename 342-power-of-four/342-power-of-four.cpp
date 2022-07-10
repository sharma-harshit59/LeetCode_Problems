int flag = 0;
class Solution {
public:
    unordered_set<long double> s;
    
    void calc_powers() {
        long long int i = 1;
        while (i < INT_MAX) {
            s.insert(i);
            i *= 4;
        }
    }
    
    bool isPowerOfFour(int n) {
        if (!flag)
            calc_powers();
        if (s.count(n))
            return true;
        return false;
    }
};