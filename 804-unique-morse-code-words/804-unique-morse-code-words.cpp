class Solution {
public:   
    string gen_morse(string str, vector<string>& morse_code) {
        string res = "";
        for (auto i: str)
            res += morse_code[i-'a'];
        return res;
    }
    
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        string morse;
        for (auto i: words) {
            morse = gen_morse(i, morse_code);
            if (!s.count(morse))
                s.insert(morse);
        }
        return s.size();
    }
};