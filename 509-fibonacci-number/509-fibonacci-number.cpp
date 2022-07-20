class Solution {
public:
    vector<int> f{0, 1};
    int fib(int n) {
        if (n >= f.size())
            f.push_back(fib(n-1) + fib(n-2));
        return f[n];
    }
};