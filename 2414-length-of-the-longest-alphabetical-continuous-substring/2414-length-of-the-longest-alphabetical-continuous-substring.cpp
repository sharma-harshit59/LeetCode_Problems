class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i = 1, temp_size = 1, max_size = 0;
        while (i < s.size()) {
            if (s[i] == (s[i-1] + 1))
                temp_size++;
            else {
                max_size = max(max_size, temp_size);
                temp_size = 1;
            }
            i++;
        }
        return max(max_size, temp_size);
    }
};