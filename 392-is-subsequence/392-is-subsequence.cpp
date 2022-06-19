class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sidx = 0, tidx = 0;
        while (tidx < t.size()) {
            if (t[tidx] == s[sidx])
                sidx++;
            tidx++;
        }
        if (sidx == s.size())
            return true;
        return false;
    }
};