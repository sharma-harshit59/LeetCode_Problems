class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<float> pq;
        double init_sum = 0, sum, temp;
        for (auto i: nums) {
            pq.push(i);
            init_sum += i;
        }
        sum = init_sum;
        int count = 0;
        while ((2 * sum) > init_sum) {
            temp = pq.top()/2;
            pq.pop();
            sum -= temp;
            pq.push(temp);
            count++;
        }
        return count;
    }
};