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
    vector<int> inOrder(Node* root) {
        // code here
         stack<Node*>st;
         Node* node=root;
          vector<int>inOrder;
        while(true){
            if(node!=NULL){
                st.push(node);
                node=node->left;
                
            }else{
                if(st.empty()==true)break;
                node=st.top();
                st.pop();
                inOrder.push_back(node->data);
                node=node->right;
            }
        }
        return inOrder;
    }
};