class Solution { 
public: 
    bool canFinish(int n, vector<vector<int>>& pre) { 
        // Create adjacency list
        vector<vector<int>> adj(n); 
        for(auto& it : pre){ 
            // If [a, b] means b must be taken before a: b -> a
            adj[it[1]].push_back(it[0]); 
        } 
        
        // Calculate indegrees using n instead of V
        vector<int> indegree(n, 0); 
        for(int i = 0; i < n; i++){ 
            for(auto it : adj[i]){ 
                indegree[it]++; 
            } 
        } 
        
        // Push all nodes with 0 indegree to queue
        queue<int> q; 
        for(int i = 0; i < n; i++){ 
            if(indegree[i] == 0){ 
                q.push(i); 
            } 
        } 
        
        // Process the graph
        int count = 0; 
        while(!q.empty()){ 
            int node = q.front(); 
            q.pop(); 
            count++; // Track the number of visited nodes instead of storing them
            
            for(auto it : adj[node]){ 
                indegree[it]--; 
                if(indegree[it] == 0) {
                    q.push(it); 
                }
            } 
        } 
        
        // If we visited all nodes, no cycle exists
        return count == n; 
    } 
};
