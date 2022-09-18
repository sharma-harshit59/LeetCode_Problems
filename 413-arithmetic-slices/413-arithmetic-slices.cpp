class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3)
            return 0;
        vector<int> available;
        int size = 2, i = 2, last_diff = (nums[1] - nums[0]);
        while (i < nums.size()) {
            if ((nums[i] - nums[i-1]) == last_diff)
                size++;
            else {
                if (size >= 3) available.push_back(size);
                last_diff = nums[i] - nums[i-1];
                size = 2;
            }
            i++;
        }
        available.push_back(size);
        int count = 0;
        for (int i: available)
            count += (((i-1) * (i-2)) / 2);
        return count;
    }
};