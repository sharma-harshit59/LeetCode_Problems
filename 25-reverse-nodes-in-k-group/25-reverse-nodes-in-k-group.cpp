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
    void reverse(ListNode* first, ListNode* last) {
        ListNode* temp = first;
        vector<int> arr;
        while (temp != last) {
            arr.push_back(temp -> val);
            temp = (temp -> next);
        }
        arr.push_back(last -> val);
        temp = first;
        for (int i = arr.size()-1; i >= 0; i--, temp = temp -> next)
            temp -> val = arr[i];
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *first = head, *last = head;
        int i = 1;
        while (last -> next) {
            if (i == k) {
                reverse(first, last);
                first = (last -> next);
                i = 0;
            }
            last = (last -> next);
            i++;
        }
        if (i == k)
            reverse(first, last);
        return head;
    }
};