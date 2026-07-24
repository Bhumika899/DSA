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
    TreeNode* buildTreeHelper(vector<int>& postorder, int postStart, int postEnd, 
                             vector<int>& inorder, int inStart, int inEnd, 
                             unordered_map<int, int>& inMap) {
        
        if (postStart > postEnd || inStart > inEnd) return nullptr;

        // 1. Root is now at the END of the current postorder segment
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot = inMap[root->val];
        int numsLeft = inRoot - inStart;

        // 2. Left subtree: uses postStart to postStart + numsLeft - 1
        root->left = buildTreeHelper(postorder, postStart, postStart + numsLeft - 1, 
                                      inorder, inStart, inRoot - 1, inMap);
        
        // 3. Right subtree: uses postStart + numsLeft to postEnd - 1 (excludes the root)
        root->right = buildTreeHelper(postorder, postStart + numsLeft, postEnd - 1, 
                                       inorder, inRoot + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        // Pass postorder instead of preorder, utilizing the total size minus 1
        return buildTreeHelper(postorder, 0, postorder.size() - 1, 
                               inorder, 0, inorder.size() - 1, inMap);
    }
};
