
/*  Structure of a Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    int maxWidth(Node* root) {
        if(!root) return 0;
        
        long long ans = 0;
        // Use long long inside the queue to prevent overflow
        queue<pair<Node*, long long>> q; 
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            long long mmin = q.front().second; 
            long long first = 0, last = 0; // Changed to long long
            
            for(int i = 0; i < size; i++){
                long long cur_id = q.front().second - mmin;
                Node* node = q.front().first;
                q.pop();
                
                if(i == 0) first = cur_id;
                if(i == size - 1) last = cur_id;
                
                if (node->left) {
                    q.push({node->left, cur_id * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, cur_id * 2 + 2});
                }
            }
            // Both arguments are now long long, fixing the std::max error
            ans = max(ans, last - first + 1); 
        }
        return ans;
    }
};