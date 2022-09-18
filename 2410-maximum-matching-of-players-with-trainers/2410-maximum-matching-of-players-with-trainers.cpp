class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        priority_queue<int, vector<int>, greater<int>> p, t;
        for (int i: players)
            p.push(i);
        for (int i: trainers)
            t.push(i);
        int count = 0;
        while (!t.empty() && !p.empty()) {
            cout<< p.top() << "<=" << t.top() << "\n";
            if (t.top() >= p.top()) {
                count++;
                p.pop();
            }
            t.pop();
        }
        return count;
    }
};