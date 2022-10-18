class Solution {
public:
    string say(string s) {
        string res = "";
        vector<pair<char, int>> sayit;
        char ch = s[0];
        int size = 1;
        for (int i = 1; i < s.size(); i++) {
            if (ch != s[i]) {
                sayit.push_back({ch, size});
                size = 0;
                ch = s[i];
            }
            size++;
        }
        sayit.push_back({ch, size});
        for (int i = 0; i < sayit.size(); i++) {
            res += char(sayit[i].second + '0');
            res += sayit[i].first;
        }
        return res;
    }
    
    string countAndSay(int n) {
        string cnt = "1";
        n--;
        while (n--)
            cnt = say(cnt);
        return cnt;
    }
};