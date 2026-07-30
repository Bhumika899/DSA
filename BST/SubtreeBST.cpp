class Solution {
public:
    class NodeValue {
    public:
        int minNode;
        int maxNode;
        int maxSize;

        NodeValue(int minNode, int maxNode, int maxSize) {
            this->minNode = minNode;
            this->maxNode = maxNode;
            this->maxSize = maxSize;
        }
    };

private:
    NodeValue largestBSTHelper(Node* root) {

        // Base case: empty tree is a valid BST
        if (root == nullptr) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        NodeValue left = largestBSTHelper(root->left);
        NodeValue right = largestBSTHelper(root->right);

        // Check whether the current subtree is a BST
        if (left.maxNode < root->data &&
            root->data < right.minNode) {

            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // Current subtree is not a BST
        return NodeValue(
            INT_MIN,
            INT_MAX,
            max(left.maxSize, right.maxSize)
        );
    }

public:
    int largestBst(Node* root) {
        return largestBSTHelper(root).maxSize;
    }
};