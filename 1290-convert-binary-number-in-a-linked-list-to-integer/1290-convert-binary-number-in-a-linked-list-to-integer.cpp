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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        unsigned int power = 1, num = 0;
        while ((temp -> next) != nullptr) {
            power *= 2;
            temp = (temp -> next);
        }
        while (head != nullptr) {
            num += ((head -> val) * power);
            power /= 2;
            head = (head -> next);
        }
        return num;
    }
};