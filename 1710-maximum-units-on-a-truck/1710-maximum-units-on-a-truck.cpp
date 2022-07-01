class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[1] > b[1])
            return true;
        return false;
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int count = 0;
        for (int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
            if (boxTypes[i][0] <= truckSize) {
                count += (boxTypes[i][1] * boxTypes[i][0]);
                truckSize -= boxTypes[i][0];
            }
            else {
                count += (boxTypes[i][1] * truckSize);
                truckSize = 0;
            }
        }
        return count;
    }
};