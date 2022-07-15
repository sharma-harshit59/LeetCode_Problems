class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_n = (mean * (n + rolls.size())) - accumulate(rolls.begin(), rolls.end(), 0);
        if ((sum_n > (n * 6)) || (sum_n < n))
            return {};
        if (sum_n == (n * 6))
            return vector<int>(n, 6);
        vector<int> res;
        while (n > 1) {
            res.push_back(sum_n / n--);
            sum_n -= *(res.rbegin());
        }
        res.push_back(sum_n);
        return res;
    }
};