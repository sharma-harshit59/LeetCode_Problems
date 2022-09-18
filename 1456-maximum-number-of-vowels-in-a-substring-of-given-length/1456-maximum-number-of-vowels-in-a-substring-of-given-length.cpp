class Solution {
public:
    bool is_vowel(char c) {
        return (c == 'a') || (c == 'e') ||(c == 'i') ||(c == 'o') ||(c == 'u');
    }
    
    int maxVowels(string s, int k) {
        string temp = "";
        int low = 0, high = 0, count = 0, max_count = 0;
        
        for (high; high < k; high++)
            count += is_vowel(s[high]);
        max_count = max(count, max_count);
        if (max_count == k)
            return k;
        
        while (high < s.size()) {
            count -= is_vowel(s[low++]);
            count += is_vowel(s[high++]);
            max_count = max(count, max_count);
            if (max_count == k)
                return k;
        }
        return max_count;
    }
};