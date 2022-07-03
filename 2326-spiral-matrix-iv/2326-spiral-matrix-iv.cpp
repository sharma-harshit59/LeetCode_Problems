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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<int> temp(n, -1);
        vector<vector<int>> mat(m, temp);
        int upper_row = 0, lower_row = m-1, left_col = 0, right_col = n-1;
        int i = 0, j = 0;
        while (head != nullptr) {
            while (head != nullptr && j <= right_col) {
                mat[i][j++] = (head -> val);
                head = (head -> next);
            }
            i++;
            j--;
            upper_row++;
            while (head != nullptr && i <= lower_row) {
                mat[i++][j] = (head -> val);
                head = (head -> next);
            }
            j--;
            i--;
            right_col--;
            while (head != nullptr && j >= left_col) {
                mat[i][j--] = (head -> val);
                head = (head -> next);
            }
            i--;
            j++;
            lower_row--;
            while (head != nullptr && i >= upper_row) {
                mat[i--][j] = (head -> val);
                head = (head -> next);
            }
            j++;
            i++;
            left_col++;
        }
        return mat;
    }
};