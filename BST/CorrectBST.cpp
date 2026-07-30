/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
private:
    Node* prev;
    Node* first;
    Node* middle;
    Node* last;

    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        // Check whether BST property is violated
        if (prev != NULL && root->data < prev->data) {

            // First violation
            if (first == NULL) {
                first = prev;
                middle = root;
            }

            // Second violation
            else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }

public:
    Node* correctBST(Node* root) {

        first = middle = last = NULL;
        prev = NULL;

        inorder(root);

        // Non-adjacent swapped nodes
        if (first != NULL && last != NULL) {
            swap(first->data, last->data);
        }

        // Adjacent swapped nodes
        else if (first != NULL && middle != NULL) {
            swap(first->data, middle->data);
        }

        return root;
    }
};