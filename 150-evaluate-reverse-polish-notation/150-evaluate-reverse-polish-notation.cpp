class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> op;
        int op1, op2;
        for (string s: tokens) {
            if ((s == "+") || (s == "-") || (s == "*") || (s == "/")) {
                op2 = op.top();
                op.pop();
                op1 = op.top();
                op.pop();
                if (s == "+")
                    op.push(op1 + op2);
                else if (s == "-")
                    op.push(op1 - op2);
                else if (s == "*")
                    op.push(op1 * op2);
                else
                    op.push(op1 / op2);
            }
            else
                op.push(stoi(s));
        }
        return op.top();
    }
};