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
    int findCeil(Node* root, int x) {
        // code here
        int ceil=-1;
        while(root){
            if(root->data==x){
                ceil=root->data;
                return ceil;
            }
            if(x>root->data){
                root=root->right;
            }else{
                ceil=root->data;
                root=root->left;
            }
        }
        return ceil;
    }
};
