class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string substr = "", temp = "";
        int i = 0, rep;
        while (i <= s.size()/2) {
            substr += s[i];
            rep = (s.size() / substr.size());
            if ((rep > 1) && ((substr.size() * rep) == s.size())) {
                while (rep--)
                    temp += substr;
                if (temp == s)
                    return true;
            }
            temp = "";
            i++;
        }
        return false;
    }
};