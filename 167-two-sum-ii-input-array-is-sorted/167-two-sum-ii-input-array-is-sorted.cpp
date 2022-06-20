class Solution {
public:
    int search(vector<int>& nums, int target, int low) {
        int high = nums.size()-1, mid;
        while (low <= high) {
            mid = low + ((high - low) / 2);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low, high, temp;
        for (int i = 0; i < numbers.size(); i++) {
            temp = search(numbers, target - numbers[i], i+1);
            if (temp != -1) {
                low = i + 1;
                high = temp + 1;
                break;
            }
        }
        return {low, high};
    }
};