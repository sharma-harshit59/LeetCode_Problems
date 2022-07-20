class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 1, temp;
        for (int i = n-1; i >= 0 && carry; i--) {
            temp = (digits[i] + carry);
            carry = (temp / 10);
            digits[i] = (temp % 10);
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};