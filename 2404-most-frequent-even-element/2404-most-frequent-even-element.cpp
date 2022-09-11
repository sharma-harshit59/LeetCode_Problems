class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i: nums)
            if (i % 2 == 0)
                cnt[i]++;
        if (cnt.size()) {
            int freq = 0, res = 0;
            for (auto i: cnt) {
                if (i.second > freq) {
                    freq = i.second;
                    res = i.first;
                }
                else if (i.second == freq)
                    res = min(res, i.first);
                else;
            }
            return res;
        }
        else
            return -1;
    }
};