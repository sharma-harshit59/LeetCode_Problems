class Solution {
public:
    int replace_num(int num) {
        int res = 0;
        while (num) {
            res += ((num % 10) * (num % 10));
            num /= 10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        set<int> s;
        while (n != 1) {
            s.insert(n);
            n = replace_num(n);
            if (s.count(n))
                return false;
        }
        return true;
    }
};