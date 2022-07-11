class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(), len = ((2 * k) + 1);
        long long int sum = 0;
        vector<int> avgs(n, -1);
        if (n < len)
            return avgs;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i - len >= 0)
                sum -= nums[i - len];
            if (i >= len - 1)
                avgs[i - k] = (sum / len);
        }
        return avgs;
    }
};