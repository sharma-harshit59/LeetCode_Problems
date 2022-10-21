class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hmap;
        for (int i = 0; i < nums.size(); i++) {
            if (hmap.count(nums[i]) && ((i - hmap[nums[i]]) <= k))
                return true;
            hmap[nums[i]] = i;
        }
        return false;
    }
};