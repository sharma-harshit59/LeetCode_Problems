class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char, int> pos;
        for (int i = 0; i < s.size(); i++) {
            if (pos.count(s[i])) {
                if ((pos[s[i]] + distance[s[i]-'a'] + 1) != i)
                    return false;
            }
            else
                pos[s[i]] = i;
        }
        return true;
    }
};