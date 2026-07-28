/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        
        TreeNode* cur = root;
        
        // Both target nodes are in the right subtree
        if (cur->val < p->val && cur->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // Both target nodes are in the left subtree
        if (cur->val > p->val && cur->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // We found the split point, which is the Lowest Common Ancestor
        return root;
    }
};
