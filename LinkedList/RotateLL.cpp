/* Structure of class Node is assumed as:
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    Node* rotate(Node* head, int k) {
        // Edge case: if list is empty, has 1 node, or no rotation needed
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        
        // 1. Find the length of the list and track the tail node
        Node* tail = head;
        int len = 1;
        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }
        
        // 2. Handle cases where k >= len using modulo
        k = k % len;
        if (k == 0) {
            return head; // No rotation needed if k is a multiple of len
        }
        
        // 3. Connect tail to head to form a temporary circular loop
        tail->next = head;
        
        // 4. For left rotation, the new tail is exactly at the k-th node
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }
        
        // 5. The new head will be the node next to the new tail
        head = newTail->next;
        
        // 6. Break the circular link
        newTail->next = nullptr;
        
        return head;
    }
};

