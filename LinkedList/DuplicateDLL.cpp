/* Structure of a linked list node 
class Node { 
public: 
    int data; 
    Node* next; 
    Node* prev; 
    Node(int value) { 
        data = value; 
        next = nullptr; 
        prev = nullptr; 
    } 
}; */

class Solution { 
public: 
    Node* removeDuplicates(Node* headRef) { 
        // Handle empty list or single-node list
        if (headRef == nullptr || headRef->next == nullptr) {
            return headRef;
        }

        Node* temp = headRef; 

        while (temp != nullptr && temp->next != nullptr) { 
            Node* nextNode = temp->next; 

            // Loop to skip and delete all consecutive duplicate nodes
            while (nextNode != nullptr && nextNode->data == temp->data) { 
                Node* duplicate = nextNode; 
                nextNode = nextNode->next; 
                delete duplicate; // Use delete instead of free
            } 

            // Re-link the next pointer
            temp->next = nextNode; 

            // Re-link the prev pointer if we haven't reached the end of the list
            if (nextNode != nullptr) {
                nextNode->prev = temp; 
            }

            // Move to the next unique node
            temp = temp->next; 
        } 

        return headRef; // Remember to return the modified list head
    } 
};
