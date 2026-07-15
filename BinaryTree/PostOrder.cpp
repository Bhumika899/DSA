/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    void postOrder(Node* root, vector<int>& res) {
        if (root == nullptr)
            return;

        // Traverse left subtree
        postOrder(root->left, res);

        // Traverse right subtree
        postOrder(root->right, res);

        // Visit current node
        res.push_back(root->data);
    }

    vector<int> postOrder(Node* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};