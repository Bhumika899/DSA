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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // If fast reaches the end, it means we need to remove the head node
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head; // Correct memory deallocation
            return newHead;
        }
        
        // Move both pointers until fast reaches the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Disconnect and safely delete the target node
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode; // Changed from free(delNode)
        
        return head;
    }
};
