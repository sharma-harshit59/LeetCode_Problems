class Solution {
public:
    string addBinary(string a, string b) {
        int i = (a.size() - 1), j = (b.size() - 1);
        int carry = 0, temp;
        string res = "";
        while ((i >= 0) || (j >= 0) || carry) {
            temp = carry;
            temp += ((i >= 0) ? (a[i--] - '0') : 0);
            temp += ((j >= 0) ? (b[j--] - '0') : 0);
            carry = (temp / 2);
            res = to_string(temp % 2) + res;
        }
        return res;
    }
};