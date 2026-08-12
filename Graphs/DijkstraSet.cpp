#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Set stores pairs of {distance, node} sorted in ascending order
        set<pair<int, int>> st;
        
        // Initialize distances to infinity (1e9)
        vector<int> dist(V, 1e9);
        
        // Distance from source to itself is 0
        dist[S] = 0;
        st.insert({0, S});
        
        while (!st.empty()) {
            // Get the node with the minimum distance
            auto it = *(st.begin());
            int node = it.second;
            int nodeDist = it.first;
            st.erase(st.begin()); // Efficiently erase by iterator
            
            // Traverse all adjacent neighbors
            for (auto neighbor : adj[node]) {
                int adjNode = neighbor[0];
                int edgeW = neighbor[1];
                
                // If a shorter path to the adjacent node is found
                if (nodeDist + edgeW < dist[adjNode]) {
                    
                    // If the node already exists in the set, remove its old path record
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    
                    // Update the shortest distance
                    dist[adjNode] = nodeDist + edgeW;
                    
                    // Insert the updated path into the set
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
