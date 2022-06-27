class Solution {
public:
    int minPartitions(string n) {
        int count = 0;
        for (char ch: n) {
            if (ch == '9')
                return 9;
            else {
                if (ch > (count + '0'))
                    count = ch - '0';
            }
        }
        return count;
    }
};