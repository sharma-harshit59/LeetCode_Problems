class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> container;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (container.count(s[i])) {
                container.clear();
                count++;
            }
            container.insert(s[i]);
        }
        return ++count;
    }
};