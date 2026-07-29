/* Definition for Node class
Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
public:
    int inOrderSuccessor(Node *root, Node *k) {
        Node* successor = nullptr;
        
        while (root != nullptr) {
            // If target data is greater than or equal to current root data,
            // the successor must be in the right subtree.
            if (k->data >= root->data) {
                root = root->right;
            } 
            // If target data is smaller, current root is a potential successor.
            // Move left to see if there is a smaller valid successor.
            else {
                successor = root;
                root = root->left;
            }
        }
        
        // Return the integer data if found, otherwise return -1
        return (successor != nullptr) ? successor->data : -1;
    }
};
