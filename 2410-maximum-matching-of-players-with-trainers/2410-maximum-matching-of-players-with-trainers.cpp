class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0, count = 0;
        while (i < players.size() && j < trainers.size()) {
            if (trainers[j] < players[i])
                j++;
            else {
                count++;
                i++;
                j++;
            }
        }
        return count;
    }
};