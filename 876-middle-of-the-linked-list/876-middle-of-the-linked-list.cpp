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
    ListNode* middleNode(ListNode* head) {
        /*
        We define two pointers - fast & slow, where fast will move two pointers
        ahead everytime (if possible), and slow will move one pointer ahead everytime
        */
        ListNode *fast = head, *slow = head;
        while ((fast -> next) && (fast -> next -> next)) { // As we have to move two pointers ahead, we have to check both conditions
            fast = (fast -> next -> next);
            slow = (slow -> next);
        }
        /*
        The above loop return the first middle node, as for even number of nodes
        the fast pointer ends at the second last node, which leads us to slow at
        the first middle node. So, we position the slow one pointer ahead, if the
        fast pointer is at the second last node
        */
        if (fast -> next)
            slow = slow -> next;
        return slow;
    }
};
