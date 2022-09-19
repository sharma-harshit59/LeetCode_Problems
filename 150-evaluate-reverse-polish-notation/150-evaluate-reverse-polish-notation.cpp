class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> nums;
        long a, b;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a + b);
            }
            else if (tokens[i] == "-") {
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a - b);
            }
            else if (tokens[i] == "*") {
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a * b);
            }
            else if (tokens[i] == "/") {
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(a / b);
            }
            else
                nums.push(stoi(tokens[i]));
        }
        return nums.top();
    }
};