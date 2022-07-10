class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for (int i: nums)
            if (i > 0)
                s.insert(i);
        int i = 1;
        while (s.count(i))
            i++;
        return i;
    }
};