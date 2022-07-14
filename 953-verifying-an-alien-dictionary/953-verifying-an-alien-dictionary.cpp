class Solution {
public:
    bool isAlienSorted(vector<string> words, string order) {
        int map[26];
        for (int i = 0; i < 26; i++)
            map[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = map[c - 'a'];
        return is_sorted(words.begin(), words.end());
    }
};