class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        swap(arr, nums);
    }
    
    int sumRange(int left, int right) {
        return accumulate(arr.begin() + left, arr.begin() + right + 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */