class Solution {
public:
    int countNodes(Node* root) {
        if(root == NULL) return 0;
        
        int lh = findLeft(root);
        int rh = findRight(root);
        
        // If left and right heights are equal, it's a perfect binary tree
        if(lh == rh) return (1 << lh) - 1;
        
        // If not, recursively count nodes in left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
private:
    int findLeft(Node* node) {
        int ht = 0;
        while(node) {
            ht++;
            node = node->left;
        }
        return ht;
    }
    
    int findRight(Node* node) {
        int ht = 0;
        while(node) {
            ht++;
            node = node->right; // Fixed typo: node->rigt -> node->right
        }
        return ht;
    }
};
