class Solution {
public:
    long long minimalKSum(vector<int>& nums, long long int k) {
        sort(nums.begin(), nums.end());
        unordered_set<int> s;
        long long int sum = (k * (k + 1)) / 2;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= k && !s.count(nums[i])) {
                sum += (++k - nums[i]);
                s.insert(nums[i]);
            }
        }
        return sum;
    }
};