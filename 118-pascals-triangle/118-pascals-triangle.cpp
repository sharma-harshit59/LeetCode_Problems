class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    temp.push_back(1);
                    if (j == i) {
                        res.push_back(temp);
                        temp = {};
                    }
                }
                else
                    temp.push_back(res[i-1][j] + res[i-1][j-1]);
            }
        }
        return res;
    }
};