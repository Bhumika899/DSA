/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
           vector<int> ans;

    if(node == NULL)
        return ans;

    stack<Node*> st;
    Node* curr = node;
      while(curr != NULL || !st.empty()) {

        if(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
              else {

            Node* temp = st.top()->right;
  if(temp == NULL) {

                temp = st.top();
                st.pop();
                ans.push_back(temp->data);

                while(!st.empty() && temp == st.top()->right) {
                       temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);

                }

            }

            else {
                curr = temp;
            }
        }
    }

    return ans;
    }
};