class Solution {
public:
    string reverseVowels(string s) {
        vector<int> sw;
        for (int i = 0; i < s.size(); i++)
            if ((s[i]=='a') || (s[i]=='e') || (s[i]=='i') || (s[i]=='o') || (s[i]=='u') || (s[i]=='A') || (s[i]=='E') || (s[i]=='I') || (s[i]=='O') || (s[i]=='U'))
                sw.push_back(i);
        int i = 0, j = sw.size()-1;
        while (i < j)
            swap(s[sw[i++]], s[sw[j--]]);
        return s;
    }
};