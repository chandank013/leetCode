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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> values;

        ListNode* curr = head;

        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        sort(values.begin(), values.end());

        curr = head;
        int i = 0;

        while (curr != nullptr) {
            curr->val = values[i++];
            curr = curr->next;
        }

        return head;
    }
};