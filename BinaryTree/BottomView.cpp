/* Definition for Node class
Node {
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
public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            // FIX 1: Renamed variable to avoid masking the function parameter 'root'
            Node* currNode = it.first; 
            int line = it.second;
            
            mpp[line] = currNode->data;
            
            // FIX 2: Replaced curly braces with parentheses for q.push()
            if (currNode->left != NULL) {
                q.push({currNode->left, line - 1}); 
            }
            if (currNode->right != NULL) {
                q.push({currNode->right, line + 1});
            }
        }
        
        // FIX 3: Changed 'map' to your variable name 'mpp'
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};