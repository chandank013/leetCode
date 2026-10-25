/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }

        stack<Node*> st;
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->child != nullptr) {
                if (curr->next != nullptr) {
                    st.push(curr->next);
                }

                Node* child = curr->child;

                curr->next = child;
                child->prev = curr;
                curr->child = nullptr;
            }
            else if (curr->next == nullptr && !st.empty()) {
                Node* nextNode = st.top();
                st.pop();

                curr->next = nextNode;
                nextNode->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};