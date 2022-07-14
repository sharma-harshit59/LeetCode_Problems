class Solution {
public:
    string freqAlphabets(string s) {
        int i = 0, n = s.size(), temp;
        string res = "";
        while (i < n) {
            if (((i + 2) < n) && (s[i + 2] == '#')) {
                temp = (((s[i] - '0') * 10) + (s[i + 1] - '0'));
                i += 2;
            }
            else
                temp = (s[i] - '0');
            res += char(temp + 'a' - 1);
            i++;
        }
        return res;
    }
};