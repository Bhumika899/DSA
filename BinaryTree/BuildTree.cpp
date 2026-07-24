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
    // Helper function placed properly inside the class
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                              vector<int>& inorder, int inStart, int inEnd, 
                              unordered_map<int, int>& inMap) {
        
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        // Uses root->val to match LeetCode's TreeNode definition
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->val]; 
        int numsLeft = inRoot - inStart;

        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, 
                                     inorder, inStart, inRoot - 1, inMap);
        
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, 
                                      inorder, inRoot + 1, inEnd, inMap);

        return root; 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Switched to unordered_map for O(1) lookups to make it faster
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, preorder.size() - 1, 
                               inorder, 0, inorder.size() - 1, inMap);
    }
};