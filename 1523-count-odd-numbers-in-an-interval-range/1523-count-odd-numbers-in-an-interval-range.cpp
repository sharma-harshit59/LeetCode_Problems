class Solution {
public:
    int countOdds(int low, int high) {
        int n;
        if (low % 2 == 0 && high % 2 == 0)
            return ((high - low) / 2);
        return (((high - low) / 2) + 1);
    }
};