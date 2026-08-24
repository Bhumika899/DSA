class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Fix 1: Use 'ListNode' instead of 'Node'
        ListNode* dummyHead = new ListNode(-1); 
        ListNode* curr = dummyHead;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        
        while(temp1 != nullptr || temp2 != nullptr) {
            int sum = carry;
            
       
            if(temp1) sum += temp1->val;
            if(temp2) sum += temp2->val;
            

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;
            
          
            curr->next = newNode;
            curr = curr->next;
            
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        
        if(carry) {
       
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
