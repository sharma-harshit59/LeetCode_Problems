class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        hC.push_back(h);
        hC.push_back(0);
        vC.push_back(w);
        vC.push_back(0);
        sort(hC.begin(), hC.end());
        sort(vC.begin(), vC.end());
        long long int row = 0, col = 0, temp;
        for (int i = 1; i < hC.size(); i++) {
            temp = hC[i] - hC[i-1];
            if (temp > row)
                row = temp;
        }
        for (int i = 1; i < vC.size(); i++) {
            temp = vC[i] - vC[i-1];
            if (temp > col)
                col = temp;
        }
        return (row * col) % 1000000007;
    }
};