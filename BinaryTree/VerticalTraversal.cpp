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
    vector<vector<int>> verticalOrder(Node *root) {

        if(root == NULL)
            return {};

        map<int, vector<int>> nodes;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while(!q.empty()) {

            auto p = q.front();
            q.pop();

            Node* node = p.first;
            int hd = p.second;

            nodes[hd].push_back(node->data);

            if(node->left)
                q.push({node->left, hd - 1});

            if(node->right)
                q.push({node->right, hd + 1});
        }

        vector<vector<int>> ans;

        for(auto &x : nodes)
            ans.push_back(x.second);

        return ans;
    }
};