class Solution {
  public:
  Node* nextRight=NULL;
    void flatten(Node *root) {
        // code here
        if(root==NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=nextRight;
        nextRight=root;
    }
};