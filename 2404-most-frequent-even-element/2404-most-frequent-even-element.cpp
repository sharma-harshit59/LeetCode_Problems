class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int val = INT_MAX, freq = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                cnt[nums[i]]++;
                if (cnt[nums[i]] > freq) {
                    val = nums[i];
                    freq = cnt[nums[i]];
                }
                else if (cnt[nums[i]] == freq)
                    val = min(val, nums[i]);
                else;
            }
        }
        return freq ? val : -1;
    }
};