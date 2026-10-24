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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        vector<ListNode*> odd;
        vector<ListNode*> even;

        ListNode* curr = head;
        int position = 1;

        while (curr != nullptr) {
            if (position % 2 == 1) {
                odd.push_back(curr);
            } else {
                even.push_back(curr);
            }

            curr = curr->next;
            position++;
        }

        int i = 0;

        for (i = 0; i + 1 < odd.size(); i++) {
            odd[i]->next = odd[i + 1];
        }

        if (!odd.empty()) {
            odd.back()->next = even.empty() ? nullptr : even[0];
        }

        for (i = 0; i + 1 < even.size(); i++) {
            even[i]->next = even[i + 1];
        }

        if (!even.empty()) {
            even.back()->next = nullptr;
        }

        return head;
    }
};