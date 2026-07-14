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
// Updated on July 14
class Solution {
public:

    void inorder(Node* root, vector<int>& res) {
        if (root == NULL)
            return;

        inorder(root->left, res);
        res.push_back(root->data);
        inorder(root->right, res);
    }

    vector<int> inOrder(Node* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};