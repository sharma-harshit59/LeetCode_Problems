class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (int i: nums) {
            if (i == 0)
                return 0;
            else if (i < 0)
                neg++;
            else;
        }
        return (neg % 2) ? -1 : 1;
    }
};