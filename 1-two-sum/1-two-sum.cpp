class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s;
        vector<int> res(2, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (s.count(target - nums[i])) {
                res[0] = i;
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[j] == (target - nums[i])) {
                        res[1] = j;
                        break;
                    }
                }
                break;
            }
            else
                s.insert(nums[i]);
        }
        return res;
    }
};