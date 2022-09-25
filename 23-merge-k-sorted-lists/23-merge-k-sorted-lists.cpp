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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode *res = new ListNode(), *temp = res;
        int temp_val;
        while (list1 != nullptr && list2 != nullptr) {
            if ((list1 -> val) < (list2 -> val)) {
                temp_val = list1 -> val;
                list1 = list1 -> next;
            }
            else {
                temp_val = list2 -> val;
                list2 = list2 -> next;
            }
            temp -> next = new ListNode(temp_val);
            temp = temp -> next;
        }
        while (list1 != nullptr) {
            temp -> next = new ListNode(list1 -> val);
            list1 = list1 -> next;
            temp = temp -> next;
        }
        while (list2 != nullptr) {
            temp -> next = new ListNode(list2 -> val);
            list2 = list2 -> next;
            temp = temp -> next;
        }
        return res -> next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
            return nullptr;
        while (lists.size() > 1) {
            int i = 1;
            while (i < lists.size()) {
                ListNode *list1 = lists[i-1], *list2 = lists[i];
                lists[i-1] = merge(list1, list2);
                i += 2;
            }
            for (int j = 1; j < lists.size(); j++)
                lists.erase(lists.begin()+j);
        }
        return lists[0];
    }
};