class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size())
            return 0;
        if (nums.size() == 1)
            return 1;
        sort(nums.begin(), nums.end());
        int max_seq = 0, count = 1, i = 1;
        while (i < nums.size()) {
            if ((nums[i] - nums[i-1]) == 0);
            else if ((nums[i] - nums[i-1]) == 1) count++;
            else count = 1;
            i++;
            max_seq = max(max_seq, count);               
        }
        return max_seq;
    }
};