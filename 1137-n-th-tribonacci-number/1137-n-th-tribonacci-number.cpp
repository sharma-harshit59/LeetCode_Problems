class Solution {
public:
    vector<int> t{0, 1, 1};
    int tribonacci(int n) {
        while (t.size() <= n) t.push_back(*(t.rbegin()) + *(t.rbegin()+1) + *(t.rbegin()+2));
        return t[n];
    }
};