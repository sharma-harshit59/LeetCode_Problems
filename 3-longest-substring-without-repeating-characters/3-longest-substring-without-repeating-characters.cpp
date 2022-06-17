class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_size = 0;
        string str = "";
        unordered_set<char> set;
        for (int i = 0; i < s.size(); i++) {
            if (!set.count(s[i])) {
                set.insert(s[i]);
                str += s[i];
                if (str.size() > max_size)
                    max_size = str.size();
            }
            else {
                set.erase(s[i]);
                int j;
                for (j = 0; str[j] != s[i]; j++)
                    set.erase(str[j]);
                str.erase(0, j+1);
                i--;
            }
        }
        return max_size;
    }
};