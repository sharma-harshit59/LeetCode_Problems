class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> UAM;
        int M = 0;
        for (int i = 0; i < logs.size(); i++) {
            UAM[logs[i][0]].insert(logs[i][1]);
            if (UAM[logs[i][0]].size() > M)
                M = UAM[logs[i][0]].size();
        }
        vector<int> arr(k, 0);
        for (auto i: UAM)
            arr[i.second.size()-1]++;
        return arr;
    }
};