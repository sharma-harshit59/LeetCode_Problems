class Solution {
public:
    int minimumLines(vector<vector<int>>& stocks) {
        int n = stocks.size();
        if (n == 1)
            return 0;
        sort(stocks.begin(), stocks.end());
        int count = 0;
        long long int x1, x2, x3, y1, y2, y3;
        for (int i = 2; i < stocks.size(); i++) {
            x1 = stocks[i-2][0];
            x2 = stocks[i-1][0];
            x3 = stocks[i][0];
            y1 = stocks[i-2][1];
            y2 = stocks[i-1][1];
            y3 = stocks[i][1];            
            if (((y3 - y2) * (x2 - x1)) != ((y2 - y1) * (x3 - x2)))
                count++;
        }
        return ++count;
    }
};