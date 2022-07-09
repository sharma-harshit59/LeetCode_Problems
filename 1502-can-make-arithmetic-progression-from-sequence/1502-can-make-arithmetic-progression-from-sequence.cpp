class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        int Max = *max_element(arr.begin(), arr.end());
        int Min = *min_element(arr.begin(), arr.end());
        int d = ((Max - Min) / (n - 1)), temp;
        if (d) {
            vector<int> count(n);
            for (int i = 0; i < n; i++) {
                temp = (arr[i] - Min) / d;
                if ((temp < 0) || (temp >= n) || count[temp] || ((Min + temp*d) != arr[i]))
                    return false;
                else 
                    count[temp]++;
            }
            return true;    
        }
        else {
            for (int i = 1; i < arr.size(); i++)
                if (arr[i] != arr[i-1])
                    return false;
            return true;
        }
    }
};