/* 
class Node { 
public: 
    int data; 
    Node *next; 
    Node(int x) { data = x; next = NULL; } 
}; 
*/

class Solution {
public:
    int cycleStart(Node* head) {
        if (head == NULL || head->next == NULL) return -1; // Return -1 if no cycle exists

        Node* slow = head;
        Node* fast = head;
        bool hasCycle = false;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // If no cycle is found, return -1 (or 0 depending on problem constraints)
        if (!hasCycle) return -1; 

        // Step 2: Find the entry point of the cycle
        slow = head; // Reset slow to head
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next; // Move fast at the same speed as slow now
        }

        return slow->data; // slow (or fast) is now pointing to the start of the cycle
    }
};
