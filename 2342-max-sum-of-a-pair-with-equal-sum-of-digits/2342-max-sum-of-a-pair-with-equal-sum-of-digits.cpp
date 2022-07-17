class Solution {
public:
    int dig_sum(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> hmap;
        for (int i = 0; i < nums.size(); i++) {
            int temp = dig_sum(nums[i]);
            if (hmap.count(temp)) {
                if (hmap[temp].first < nums[i])
                    hmap[temp] = make_pair(nums[i], hmap[temp].first);
                else if (hmap[temp].second < nums[i])
                    hmap[temp].second = nums[i];
                else;
            }
            else
                hmap[temp] = make_pair(nums[i], -1);
        }
        
        int M = -1;
        for (auto i: hmap)
            if (i.second.second != -1)
                M = max(M, i.second.first + i.second.second);    
        
        return M;
    }
};