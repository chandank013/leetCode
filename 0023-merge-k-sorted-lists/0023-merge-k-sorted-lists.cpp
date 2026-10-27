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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        // Collect values from all lists
        for (ListNode* head : lists) {
            while (head != nullptr) {
                values.push_back(head->val);
                head = head->next;
            }
        }

        // Sort all values
        sort(values.begin(), values.end());

        // Build the resulting linked list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        for (int value : values) {
            tail->next = new ListNode(value);
            tail = tail->next;
        }

        return dummy.next;
    }
};