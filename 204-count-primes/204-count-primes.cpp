class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (is_prime[i]) {
                count++;
                for (int j = 2*i; j < n; j += i)
                    is_prime[j] = false;
            }
        }
        return count;
    }
};