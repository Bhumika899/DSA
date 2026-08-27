/* Structure of Doubly Linked List Node
class Node {
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
    // Helper function to find the tail node
    Node* findTail(Node* head) {
        Node* tail = head;
        while (tail != nullptr && tail->next != nullptr) 
            tail = tail->next;
        return tail;
    }

    vector<vector<int>> givenSumPairs(Node* head, int target) {
        vector<vector<int>> ans; // Fixed return type
        if (head == nullptr) return ans;

        Node* left = head;
        Node* right = findTail(head); // Fixed typo 'finTail'

        // Two-pointer approach for sorted doubly linked list
        while (left != nullptr && right != nullptr && left != right && right->next != left) {
            int current_sum = left->data + right->data;

            if (current_sum == target) { // Fixed undefined variable 'k' to 'target'
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } 
            else if (current_sum < target) {
                left = left->next;
            } 
            else {
                right = right->prev;
            }
        }
        return ans;
    }
};
