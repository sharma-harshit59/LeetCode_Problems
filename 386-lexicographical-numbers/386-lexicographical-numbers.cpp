class Solution {
public:
    static bool comp(int a, int b) {
        string stra = to_string(a), strb = to_string(b);
        if (stra < strb)
            return true;
        return false;
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> res(n);
        for (int i = 1; i <= n; i++)
            res[i-1] = i;
        sort(res.begin(), res.end(), comp);
        return res;
    }
};