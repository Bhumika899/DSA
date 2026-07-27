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
    Node* insert(Node* root, int key) {
        // code  here
        if(root==NULL) return new Node(key);
        Node* cur=root;
        while(true){
            if(cur->data<=key){
                if(cur->right!=NULL)cur=cur->right;
            else{
                cur->right=new Node(key);
                break;
            }
            }else{
                if(cur->left!=NULL) cur=cur->left;
                else{
                    cur->left=new Node(key);
                    break;
                }
            }
        }
        return root;
    }
};