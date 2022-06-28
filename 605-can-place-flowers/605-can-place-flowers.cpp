class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if ((m == 1 && n == 1 && flowerbed[0] == 0) || (m == 1 && n == 0 && flowerbed[0] == 1))
            return true;
        for (int i = 0; i < m && n > 0; i++) {
            if (flowerbed[i])
                continue;
            else {
                if (i == 0) {
                    if (flowerbed[1] == 0) {
                        flowerbed[0] = 1;
                        --n;
                    }
                    else
                        continue;
                }
                else if (i == m-1) {
                    if (flowerbed[m-2] == 0) {
                        flowerbed[m-1] = 1;
                        --n;
                    }
                    else
                        continue;
                }
                else {
                    if (flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                        flowerbed[i] = 1;
                        --n;
                    }
                }
            }
        }
        if (n)
            return false;
        return true;
    }
};