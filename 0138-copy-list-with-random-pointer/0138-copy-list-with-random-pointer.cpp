/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        Node* newHead = new Node(head->val);
        Node* oldCurr = head;
        Node* newCurr = newHead;

        // Copy the next chain
        while (oldCurr->next != nullptr) {
            newCurr->next = new Node(oldCurr->next->val);
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }

        oldCurr = head;
        newCurr = newHead;

        // Find each random target by searching the original list
        while (oldCurr != nullptr) {
            if (oldCurr->random == nullptr) {
                newCurr->random = nullptr;
            } else {
                Node* searchOld = head;
                Node* searchNew = newHead;

                while (searchOld != oldCurr->random) {
                    searchOld = searchOld->next;
                    searchNew = searchNew->next;
                }

                newCurr->random = searchNew;
            }

            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
