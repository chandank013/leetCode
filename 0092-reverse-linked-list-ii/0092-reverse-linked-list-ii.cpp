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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;

        vector<ListNode*> nodes;

        for (ListNode* curr = head; curr != nullptr;
             curr = curr->next) {
            nodes.push_back(curr);
        }

        reverse(nodes.begin() + left - 1,
                nodes.begin() + right);

        for (int i = 0; i + 1 < nodes.size(); i++) {
            nodes[i]->next = nodes[i + 1];
        }

        nodes.back()->next = nullptr;

        return nodes[0];
    }
};
