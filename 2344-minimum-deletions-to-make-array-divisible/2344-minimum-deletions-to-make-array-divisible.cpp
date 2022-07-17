class Solution {
public:
    int gcd(int a, int b) {
        return (!b) ? a : gcd(b, a % b);
    }
    int minOperations(vector<int>& nums, vector<int>& nd) {
        int hcf = nd[0], count = 0, flag = 0;
        for (int i: nd)
            hcf = gcd(hcf, i);
        int res = hcf;
        for (int i: nums) {
            if (hcf % i == 0 && i <= res) {
                res = i;
                flag = 1;
            }
        }
        if (!flag)
            return -1;
        for (int i: nums)
            if (i < res)
                count++;
        return count;
    }
};