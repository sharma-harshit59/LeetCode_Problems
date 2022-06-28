class Solution {
public:
    int minDeletions(string s) {
        vector<int> count(26, 0);
        for (char ch: s)
            count[ch - 'a']++;
        sort(count.begin(), count.end());
        unordered_set<int> t;
        int cnt = 0;
        for (int i = count.size()-1; i >= 0; i--) {
            while (t.count(count[i]) && count[i] != 0) {
                cnt++;
                count[i]--;
            }
            t.insert(count[i]);
        }
        return cnt;
    }
};