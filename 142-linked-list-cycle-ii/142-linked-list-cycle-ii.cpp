/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return NULL;
        unordered_set<ListNode*> s;
        s.insert(head);
        while (head -> next) {
            if (s.count(head -> next))
                return head -> next;
            s.insert(head -> next);
            head = head -> next;
        }
        return NULL;
    }
};