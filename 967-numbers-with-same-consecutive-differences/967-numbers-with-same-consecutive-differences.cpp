class Solution {
public:
    unordered_set<int> s;
    vector<int> res;
    void gen_num(int num, int digit_left, int jump, int next_num) {
        if (next_num <= 9 && next_num >= 0) {
            num = ((num * 10) + next_num);
            digit_left--;
            if (!digit_left) {
                if (!s.count(num))
                    res.push_back(num);
                s.insert(num);
            }
            else {
                gen_num(num, digit_left, jump, next_num - jump);
                gen_num(num, digit_left, jump, next_num + jump);
            }
        }
        else
            return;
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for (int i = 1; i <= 9; i++) {
            gen_num(i, n-1, k, i-k);
            gen_num(i, n-1, k, i+k);
        }
        return res;
    }
};