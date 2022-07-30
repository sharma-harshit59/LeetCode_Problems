class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1, j;
        while (i >= 0 && s[i] == ' ')
            i--;
        j = i;
        while (j >= 0 && s[j] != ' ')
            j--;
        return i - j;
    }
};