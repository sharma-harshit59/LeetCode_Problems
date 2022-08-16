class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hmap(26, 0);
        for (auto i: s)
            hmap[i - 'a']++;
        for (int i = 0; i < s.size(); i++)
            if (hmap[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};