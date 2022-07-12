class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int M = accumulate(accounts[0].begin(), accounts[0].end(), 0), temp;
        for (int i = 1; i < accounts.size(); i++) {
            temp = accumulate(accounts[i].begin(), accounts[i].end(), 0);
            M = max(M, temp);
        }
        return M;
    }
};