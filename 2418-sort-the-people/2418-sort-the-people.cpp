class Solution {
public:    
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> arr;
        for (int i = 0; i < names.size(); i++)
            arr.push_back({heights[i], names[i]});;
        sort(arr.rbegin(), arr.rend());
        for (int i = 0; i < names.size(); i++)
            names[i] = arr[i].second;
        return names;
    }
};