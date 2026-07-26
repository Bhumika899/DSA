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
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>inorder;
        Node* cur=root;
        while(cur!=NULL){
            if(cur->left==NULL){
                inorder.push_back(cur->data);
                cur=cur->right;
                
            }
            else{
                Node* prev=cur->left;
                while(prev->right && prev->right !=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(cur->data);
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }
};