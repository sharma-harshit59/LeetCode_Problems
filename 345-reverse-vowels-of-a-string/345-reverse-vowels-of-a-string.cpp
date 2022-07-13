class Solution {
public:
    bool is_vowel(char ch) {
        return ((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U')); 
    }
    
    string reverseVowels(string s) {
        int i = -1, j = s.size();
        while (i < j) {
            do {
                i++;
            } while (i < s.size() && !is_vowel(s[i]));
            do {
                j--;
            } while (j >= 0 && !is_vowel(s[j]));
            if (i < j)
                swap(s[i], s[j]);
        }
        return s;
    }
};