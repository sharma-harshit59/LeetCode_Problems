class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> sc, tc;
        int si = 0, ti = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!sc.count(s[i]))
                sc[s[i]] = ++si;
            if (!tc.count(t[i]))
                tc[t[i]] = ++ti;
            if (sc[s[i]] != tc[t[i]])
                return false;
        }
        return true;
    }
};