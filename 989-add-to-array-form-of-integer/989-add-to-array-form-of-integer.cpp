class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0;
        for (int i = num.size()-1; i >= 0 && (carry || k); i--) {
            num[i] += (carry + (k % 10));
            carry = num[i] / 10;
            num[i] %= 10;
            k /= 10;
        }
        while (k || carry) {
            carry += (k % 10);
            num.insert(num.begin(), carry % 10);
            carry /= 10;
            k /= 10;
        }
        return num;
    }
};