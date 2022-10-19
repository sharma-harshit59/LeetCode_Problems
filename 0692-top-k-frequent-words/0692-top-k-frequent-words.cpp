class Solution {
public:
    static bool comp(pair<string, int>& a, pair<string, int>& b) {
        return (a.second == b.second) ? (a.first < b.first) : (a.second > b.second);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string i: words)
            freq[i]++;
        
        vector<pair<string, int>> arr;
        for (auto i: freq)
            arr.push_back({i.first, i.second});
        sort(arr.begin(), arr.end(), comp);
        
        vector<string> res;
        int i = 0;
        while (k--) {
            res.push_back(arr[i].first);
            i++;
        }
        return res;
    }
};