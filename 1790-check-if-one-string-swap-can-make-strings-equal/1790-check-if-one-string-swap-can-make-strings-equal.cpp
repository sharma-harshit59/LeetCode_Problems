class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (idx1 == -1)
                    idx1 = i;
                else {
                    idx2 = i;
                    break;
                }
            }
        }
        if (idx2 == -1) {
            if (idx1 == -1)
                return true;
            return false;
        } 
        else {
            swap(s1[idx1], s1[idx2]);
            return s1 == s2;
        }
    }
};