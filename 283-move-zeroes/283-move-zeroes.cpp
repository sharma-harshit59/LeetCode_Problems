class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0, i = 0, j = 0;
        while (i < nums.size()) {
            if (!nums[i])
                count++;
            else
                nums[j++] = nums[i];
            i++;
        }
        while (count--)
            nums[--i] = 0;
    }
};

/*
1 1 0 3 12
count = 2
i = 3
j = 1
size = 5
*/