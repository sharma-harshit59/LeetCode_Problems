class Solution {
public:
    static int count_1(int num) {
        int count = 0;
        while (num) {
            num &= (num - 1);
            count++;
        }
        return count;
    }
    
    static bool comp(int a, int b) {
        int m = count_1(a), n = count_1(b);
        return ((m == n) ? (a < b) : (m < n));
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};