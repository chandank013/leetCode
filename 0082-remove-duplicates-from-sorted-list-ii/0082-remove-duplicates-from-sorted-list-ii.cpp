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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (ListNode* curr = head; curr != nullptr;
             curr = curr->next) {

            int count = 0;

            for (ListNode* temp = head; temp != nullptr;
                 temp = temp->next) {
                if (temp->val == curr->val) {
                    count++;
                }
            }

            if (count == 1) {
                tail->next = new ListNode(curr->val);
                tail = tail->next;
            }
        }

        return dummy.next;
    }
};
