class Solution {
public:
    bool is_char(char ch) {
        return ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'));
    }
    
    string reverseOnlyLetters(string s) {
        int low = 0, high = s.size()-1;
        while (low < high) {
            while ((low < high) && (!is_char(s[low]))) low++;
            while ((low < high) && (!is_char(s[high]))) high--;
            if (low < high)
                swap(s[low++], s[high--]);
        }
        return s;
    }
};