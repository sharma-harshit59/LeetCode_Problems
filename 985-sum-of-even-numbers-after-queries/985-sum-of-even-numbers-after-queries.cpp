class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int even_sum = 0, initial, latest, idx, val;
        for (int i: nums)
            if (i % 2 == 0)
                even_sum += i;
        
        for (int i = 0; i < queries.size(); i++) {
            val = queries[i][0];
            idx = queries[i][1];
            initial = nums[idx];
            nums[idx] += val;
            latest = nums[idx];
            if (initial % 2 == 0)
                even_sum -= initial;
            if (latest % 2 == 0)
                even_sum += latest;
            res.push_back(even_sum);
        }
        return res;
    }
};