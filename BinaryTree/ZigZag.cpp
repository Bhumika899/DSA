/* Structure of the node of the binary tree is as
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    // Function to store the zigzag order traversal of tree in a 1D vector.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }

        queue<Node*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                Node* currNode = nodesQueue.front();
                nodesQueue.pop();

                // Determine position based on current traversal direction
                int index = leftToRight ? i : (size - 1 - i);
                row[index] = currNode->data;

                if (currNode->left) {
                    nodesQueue.push(currNode->left);
                }
                if (currNode->right) {
                    nodesQueue.push(currNode->right);
                }
            }

            // Flip the direction flag for the next level
            leftToRight = !leftToRight;

            // Flatten the 2D rows into the single 1D result vector
            for (int val : row) {
                result.push_back(val);
            }
        }
        
        return result;
    }
};
