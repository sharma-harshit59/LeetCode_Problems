class Solution {
public:
    bool is_vowel(char ch) {
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
    
    bool halvesAreAlike(string s) {
        int left = 0, right = 0, i;
        for (i = 0; i < s.size()/2; i++)
            if (is_vowel(s[i]))
                left++;
        for (i; i < s.size(); i++)
            if (is_vowel(s[i]))
                right++;
        return (left == right);
    }
};