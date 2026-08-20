class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Base case: if the list is empty or has only one node
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Save the start of the even list
        
        // FIX 1: Change !even to even
        while (even && even->next) {
            odd->next = even->next;   // Connect current odd node to next odd node
            odd = odd->next;          // Move odd pointer forward
            
            even->next = odd->next;   // Connect current even node to next even node
            even = even->next;        // Move even pointer forward
        }
        
        odd->next = evenHead;         // Attach the even list to the end of the odd list
        return head;
    }
};
