/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool isSymmetric(Node* root) {
        // code here
        return (root==NULL) || isSymmetricHelp(root->left,root->right);
        
    }
      bool isSymmetricHelp(Node* left,Node*right) {
          if(left==NULL|| right==NULL)
          return left==right;
          if(left->data!=right->data) return false;
          return isSymmetricHelp(left->left,right->right)&&
          isSymmetricHelp(left->right,right->left);
          
      }
    
};