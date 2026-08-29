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
        flattenList(head);
        return head;
    }

    Node* flattenList(Node* head) {

        if (head == nullptr)
            return nullptr;

        Node* curr = head;
        Node* last = nullptr;

        while (curr != nullptr) {

            Node* next = curr->next;

            // If child exists
            if (curr->child != nullptr) {

                Node* child = curr->child;

                // Flatten child list
                Node* childTail = flattenList(child);

                // Connect curr -> child
                curr->next = child;
                child->prev = curr;

                // Remove child pointer
                curr->child = nullptr;

                // Connect child tail -> next
                if (next != nullptr) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                last = childTail;
            }
            else {
                last = curr;
            }

            curr = next;
        }

        return last;
    }
};