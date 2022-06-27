class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left <= right) {
            if ('0' <= s[left] && s[left] <= '9');
            else if ('a' <= s[left] && s[left] <= 'z');
            else if ('A' <= s[left] && s[left] <= 'Z') s[left] += ('a' - 'A');
            else {left++; continue;}
            
            if ('0' <= s[right] && s[right] <= '9');
            else if ('a' <= s[right] && s[right] <= 'z');
            else if ('A' <= s[right] && s[right] <= 'Z') s[right] += ('a' - 'A');
            else {right--; continue;}
            
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};