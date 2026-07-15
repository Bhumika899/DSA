/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void preOrder(Node* node, vector<int>& res) {
    if (node == nullptr)
        return;

    // Visit the current node first
    res.push_back(node->data);

    // Traverse the left subtree
    preOrder(node->left, res);

    // Traverse the right subtree
    preOrder(node->right, res);
}

    vector<int> preOrder(Node* root) {
        // code here
         vector<int> res;
    preOrder(root, res);
    return res;
    }
};