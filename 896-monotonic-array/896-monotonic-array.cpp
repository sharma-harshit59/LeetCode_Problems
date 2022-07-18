class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() < 3)
            return true;
        int flag = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                if (flag == 0) flag = 1;
                else if (flag == -1) return false;
                else;
            }
            else if (nums[i] < nums[i-1]) {
                if (flag == 0) flag = -1;
                else if (flag == 1) return false;
                else;
            }
            else;
        }
        return true;
    }
};