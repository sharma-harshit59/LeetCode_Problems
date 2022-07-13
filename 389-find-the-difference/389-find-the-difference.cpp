class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hmap;
        for (int i = 0; i < s.size(); i++) {
            hmap[s[i]]++;
            hmap[t[i]]--;
        }
        hmap[t[s.size()]]--;
        for (auto i: hmap) {
            if (i.second == -1)
                return i.first;
        }
        return 0;
    }
};