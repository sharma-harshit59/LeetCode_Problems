class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> hmap;
        for (int i = 0; i < nums.size(); i++) {
            if (hmap[nums[i]].size() && ((i - *hmap[nums[i]].rbegin()) <= k))
                    return true;
            hmap[nums[i]].push_back(i);
        }
        return false;
    }
};