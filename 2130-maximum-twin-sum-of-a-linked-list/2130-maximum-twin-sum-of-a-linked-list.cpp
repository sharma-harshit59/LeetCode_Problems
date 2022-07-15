/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head, *fast = head;
        stack<int> s;
        int M = 0, temp;
        while (fast -> next -> next) {
            s.push(slow -> val);
            slow = (slow -> next);
            fast = (fast -> next -> next);
        }
        s.push(slow -> val);
        slow = (slow -> next);
        while (!s.empty()) {
            temp = s.top() + (slow -> val);
            M = max(M, temp);
            s.pop();
            slow = (slow -> next);
        }
        return M;
    }
};