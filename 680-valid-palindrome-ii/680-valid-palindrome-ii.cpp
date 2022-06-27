class Solution {
public:
    bool validPal(string s) {
        int l = 0, r = s.size()-1;
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while (l <= r) {
            if (s[l] != s[r])
                return (validPal(s.substr(l, r - l)) || validPal(s.substr(l + 1, r - l)));
            l++;
            r--;
        }
        return true;
    }
};