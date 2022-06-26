class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int card_sum = accumulate(cardPoints.begin() + n - k, cardPoints.end(), 0);
        int low = 0, high = n - k, max = card_sum;
        if (low == high);
        else {
            while (high < cardPoints.size()) {
                card_sum += (cardPoints[low++] - cardPoints[high++]);
                if (card_sum > max)
                    max = card_sum;
            }
        }
        return max;
    }
};