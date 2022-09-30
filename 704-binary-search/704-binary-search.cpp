class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
            The variables defined below are:
            low:  stores the start-index of the search space array
            high: stores the end-index of the search space array
            mid:  stores the mid-index value of the search space array
        */
        int low = 0, high = nums.size()-1, mid;
        
        /*
            We loop until the search space vanishes, i.e., low is less
            than or equal to high. If low is greater than high, this
            means that our search space has vanished            
        */
        while (low <= high) {
            mid = low + ((high - low) / 2);
            /*
                If the value at the mid-index is equal to the target we
                return the index else, we reposition the low and high
                values to half the search space
            */
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        /*
            If no mid-index is found such that the value present at the
            index is equal to the target value, this shows that the target
            value is not present in the array, hence we return -1
        */
        return -1;
    }
};