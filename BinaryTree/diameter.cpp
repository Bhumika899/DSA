/*
Definition for Node
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
  public:
    int diameter(Node* root) {
        // code here
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    private:
    int height(Node*root,int&diameter){
        if(!root){
            return 0;
            
        }
        int lh=height(root->left,diameter);
        int rh=height(root->right,diameter);
        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
};