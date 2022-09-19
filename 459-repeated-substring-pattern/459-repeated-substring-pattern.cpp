class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string temp = "", t;
        int n = s.size(), m, repeat;
        for (int i = 0; i <= n/2; i++) {
            temp += s[i];
            t = temp;
            m = temp.size();
            repeat = (n / m);
            if (repeat < 2) continue;
            for (int j = 1; j < repeat; j++)
                t += temp;
            if (t == s)
                return true;
        }
        return false;
    }
};