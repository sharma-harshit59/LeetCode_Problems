class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        if (a.first > b.first)
            return true;
        return false;
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char ch: s)
            count[ch]++;
        vector<pair<int, int>> freq;
        for (auto i: count)
            freq.push_back(make_pair(i.second, i.first));
        sort(freq.begin(), freq.end(), comp);
        string res = "";
        for (auto i: freq)
            while (i.first--)
                res += i.second;
        return res;
    }
};