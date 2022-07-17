class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> res{0, n};
        unordered_map<int, int> count;
        for (int i: nums)
            count[i]++;
        
        for (auto i: count) {
            res[0] += i.second / 2;
            res[1] -= (i.second / 2) * 2;
        }
        return res;
    }
};