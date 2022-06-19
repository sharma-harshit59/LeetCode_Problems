class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum_right = accumulate(nums.begin() + 1, nums.end(), 0);
        int sum_left = 0, flag = 0, idx = 0;
        while ((sum_left != sum_right) && (idx < nums.size()-1)) {
            sum_left += nums[idx];
            sum_right -= nums[++idx];
            if (sum_left == sum_right)
                break;
        }
        if (sum_left == sum_right)
            return idx;
        return -1;
    }
};