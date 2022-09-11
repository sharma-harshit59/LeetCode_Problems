class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        /* The variable 'flag' has been used to keep track of any changes
           encountered while traversing the array to check for Monotonicity
           Here, we have checked the first and last element to check the type of Monotonicity */
        int flag = (nums[0] <= nums[nums.size()-1]) ? 1 : -1;
        
        /* Check if the Array is Monotonically Increasing */
        for (int i = 1; (i < nums.size()) && (flag == 1); i++)
            if (nums[i] < nums[i-1])
                flag = 0;
        
        /* Check if the Array is Monotonically Decreasing */
        for (int i = 1; (i < nums.size()) && (flag == -1); i++)
            if (nums[i] > nums[i-1])
                flag = 0;
        return flag;
    }
};