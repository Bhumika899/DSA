/* Definition for Node class
Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int val) {
            data = val;
            left = right = nullptr;
        }
};
*/

class Solution {
public:
    int findMaxSum(Node *root) {
        int maxi = INT_MIN;
        maxPath(root, maxi);
        return maxi;
    }

    int maxPath(Node* root, int &maxi) {
        if (root == nullptr) return 0;

        // Ignore negative paths by taking max with 0
        int left = max(0, maxPath(root->left, maxi));
        int right = max(0, maxPath(root->right, maxi));

        // Update the global maximum path sum passing through the current node
        maxi = max(maxi, left + right + root->data);

        // Return the maximum single path sum to the parent node
        return max(left, right) + root->data;
    }
};
