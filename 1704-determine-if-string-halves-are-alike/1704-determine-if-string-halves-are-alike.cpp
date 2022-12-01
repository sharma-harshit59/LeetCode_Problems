class Solution {
public:
    bool is_vowel(char ch) {
        /*
        As the vowels of English Alphabet are A, E, I, O, and U (a, e, i, o, and u in Smallcase), so we check if the
        character in question is a vowel or not, and return the value referring to if any character has matched or not.
        */
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }
    
    bool halvesAreAlike(string s) {
        // We declare the following variables -
        // left  : Keep the count of vowels in the Left-part of the String
        // right : Keep the count of vowels in the Right-part of the String
        // i     : Iterator variable to maintain the index of the current character of the string being parsed
        int left = 0, right = 0, i;
        // As the string has to be divided into two equal halves, we run the first loop till the central character
        for (i = 0; i < s.size()/2; i++)
            if (is_vowel(s[i]))
                left++;
        // As the previous loop ran upto the centre, we continue from their itself
        for (i; i < s.size(); i++)
            if (is_vowel(s[i]))
                right++;
        // If the values are equal, we return true, else false.
        return (left == right);
    }
};
