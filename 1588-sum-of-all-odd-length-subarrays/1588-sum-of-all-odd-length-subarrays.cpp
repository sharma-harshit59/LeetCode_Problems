class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0, contribution, n = arr.size();
        for (int i = 0; i < n; i++) {
            contribution = ceil(((i + 1) * (n - i)) / 2.0);
            res += (contribution * arr[i]);
        }
        return res;
    }
};