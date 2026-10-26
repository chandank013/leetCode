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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;

        ListNode* curr = head;

        // Count total nodes
        while (curr != nullptr) {
            n++;
            curr = curr->next;
        }

        int baseSize = n / k;
        int extraNodes = n % k;

        vector<ListNode*> result(k, nullptr);

        curr = head;

        for (int i = 0; i < k; i++) {
            if (curr == nullptr) {
                result[i] = nullptr;
                continue;
            }

            result[i] = curr;

            int partSize = baseSize;

            if (extraNodes > 0) {
                partSize++;
                extraNodes--;
            }

            // Move to the last node of this part
            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            // Save the next part's starting node
            ListNode* nextPart = curr->next;

            // End the current part
            curr->next = nullptr;

            // Move to the next part
            curr = nextPart;
        }

        return result;
    }
};