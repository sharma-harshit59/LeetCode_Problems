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
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
                res += (reverse(temp) + ' ');
                temp = "";
            }
            else
                temp += s[i];
            i++;
        }
        res += reverse(temp);
        return res;
    }
};