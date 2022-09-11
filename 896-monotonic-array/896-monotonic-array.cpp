class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag = (nums[0] <= nums[nums.size()-1]) ? 1 : -1;
        for (int i = 1; (i < nums.size()) && (flag == 1); i++)
            if (nums[i] < nums[i-1])
                flag = 0;
        for (int i = 1; (i < nums.size()) && (flag == -1); i++)
            if (nums[i] > nums[i-1])
                flag = 0;
        return (flag) ? true : false;
    }
};