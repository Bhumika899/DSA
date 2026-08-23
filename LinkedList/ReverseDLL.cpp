/* Structure of Doubly Linked List
Node class
Node {
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
}; */

class Solution {
public:
    Node *reverse(Node *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        Node* prev = nullptr;
        Node* current = head;

        while (current != nullptr) {
            // 1. Save the previous node reference and swap pointers
            prev = current->prev;
            current->prev = current->next;
            current->next = prev;

            // 2. Move to the next node in the ORIGINAL list
            // Since we just swapped current->next and current->prev,
            // the original "next" node is now stored in current->prev.
            current = current->prev; 
        }

        // 3. 'prev' points to the old head's previous element (which is the new second element).
        // The last swapped node's 'prev' pointer now points to the new head.
        return prev->prev;
    }
};
