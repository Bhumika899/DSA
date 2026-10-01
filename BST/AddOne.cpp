/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* add(TreeNode* root, int val, int depth, int curr) {
        if (root == NULL) return NULL;
        
        // FIX: intercept at depth - 1 to shift the children down
        if (curr == depth - 1) {
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;
            
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            
            // The original left subtree goes to the new left node's left child
            root->left->left = leftTemp;
            // The original right subtree goes to the new right node's right child
            root->right->right = rightTemp;
            
            return root;
        }
        
        root->left = add(root->left, val, depth, curr + 1);
        root->right = add(root->right, val, depth, curr + 1);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // Special case: if depth is 1, create a new root
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        int curr = 1;
        return add(root, val, depth, curr);
    }
};
