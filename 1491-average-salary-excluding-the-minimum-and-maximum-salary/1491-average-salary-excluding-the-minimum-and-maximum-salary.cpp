class Solution {
public:
    double average(vector<int>& salary) {
        double avg = 0, Mx = salary[0], Mi = salary[0];
        for (int i: salary) {
            avg += i;
            Mx = ((i > Mx) ? i : Mx);
            Mi = ((i < Mi) ? i : Mi);
        }
        avg -= (Mx + Mi);
        return (avg / double(salary.size() - 2));
    }
};