class Solution {
public:
    string reverse(string str) {
        int low = 0, high = str.size()-1;
        while (low < high)
            swap(str[low++], str[high--]);
        return str;
    }
    
    string reverseWords(string s) {
        string temp = "", res = "";
        for (char ch: s) {
            if (ch == ' ') {
                res += (reverse(temp) + ' ');
                temp = "";
            }
            else
                temp += ch;
        }
        res += reverse(temp);
        return res;
    }
};