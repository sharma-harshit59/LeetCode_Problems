class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        for (int i = 0; i < nums2.size(); i++) {
            int j = i + 1;
            while (j < nums2.size() && nums2[j] < nums2[i])
                j++;
            if (j == nums2.size())
                next[nums2[i]] = -1;
            else
                next[nums2[i]] = nums2[j];
        }
        for (int i = 0; i < nums1.size(); i++)
            nums1[i] = next[nums1[i]];
        return nums1;
    }
};