class Solution {
public:
    vector<string> res;
    vector<string> alphabets;
    
    void make_str(int n, string s) {
        if (n == 0)
            res.push_back(s);
        else {
            int temp = (n % 10) - 2;
            for (int i = 0; i < alphabets[temp].size(); i++)
                make_str(n/10, alphabets[temp][i] + s);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};
        alphabets.push_back("abc");
        alphabets.push_back("def");
        alphabets.push_back("ghi");
        alphabets.push_back("jkl");
        alphabets.push_back("mno");
        alphabets.push_back("pqrs");
        alphabets.push_back("tuv");
        alphabets.push_back("wxyz");
        make_str(stoi(digits), "");
        return res;
    }
};