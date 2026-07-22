/* Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
public: // FIX 1: Must be public so it can be called from outside
    vector<int> rightView(Node *root) {
        vector<int> ans;
        recursion(root, 0, ans); // FIX 2: Changed 'res' to 'ans'
        return ans;
    }

    void recursion(Node* root, int level, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        
        if (res.size() == level) {
            res.push_back(root->data);
        }
        
        // FIX 3: Traverse RIGHT child first for right view
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }
};
