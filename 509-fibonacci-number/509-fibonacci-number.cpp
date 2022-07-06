vector<int> fibonacci{0, 1};
class Solution {
public:
    int fib(int n) {
        if (fibonacci.size() >= n + 1);
        else fibonacci.push_back(fib(n-1) + fib(n - 2));
        return fibonacci[n];
    }
};