class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        int low = 0, high = nums.size()-1, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) {
                if (mid == 0) {
                    res[0] = mid;
                    break;
                }
                else if (nums[mid] > nums[mid - 1]) {
                    res[0] = mid;
                    break;
                }
                else
                    high = mid-1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        low = 0;
        high = nums.size()-1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size()-1) {
                    res[1] = mid;
                    break;
                }
                else if (nums[mid] < nums[mid + 1]) {
                    res[1] = mid;
                    break;
                }
                else
                    low = mid+1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return res;
    }
};