class Solution {
public:
    int fillCups(vector<int>& amount) {
        int MAX = *max_element(amount.begin(), amount.end());
        int MIN = *min_element(amount.begin(), amount.end());
        int MID = accumulate(amount.begin(), amount.end(), 0) - (MAX + MIN);
        int time = 0;
        
        while (((MIN + MID) > MAX) && MIN > 0) {
            time++;
            MIN--;
            MID--;
        }
        return time + MAX;
    }
};