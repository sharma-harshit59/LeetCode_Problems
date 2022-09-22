class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, i = 0;
        stack<char> stk;
        while (i < s.size()) {
            if (s[i] == '(')
                stk.push(s[i]);
            else if (stk.empty())
                count++;
            else
                stk.pop();
            i++;
        }
        return count + stk.size();
    }
};