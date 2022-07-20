class Solution {
public:
    unordered_map<string, bool> is_subseq;
    bool check_subseq(string sub, string s) {
        int i = 0, j = 0;
        while (i < s.size() && j < sub.size()) {
            if (s[i++] == sub[j])
                j++;
        }
        return (j == sub.size());
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        for (string str: words) {
            if (is_subseq.count(str))
                count += is_subseq[str];
            else if (check_subseq(str, s)) {
                is_subseq[str] = true;
                count++;
            }
            else
                is_subseq[str] = false;
        }
        return count;
    }
};